#include <iostream>
#include <math.h>
#include <omp.h>
#include <CL/sycl.hpp>


#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

using namespace std;


int main(int argc, char const *argv[])
{
    sycl::gpu_selector selector;
    sycl::queue Q(selector);

    // TODO: Check that the input image is in the args
    if (argc < 2) {
        cout << "Error no image provided " << endl;
        exit(1);
    }

    //Load image
    int img_width, img_height, channels;

    unsigned char *image = stbi_load(argv[1], &img_width, &img_height, &channels, 0);

    if (image == NULL) {
        cout << "Error while loading image" << endl;
        exit(1);
    }


    //Debug information
    cout << "Loaded image with a width of " << img_width << " height of " << img_height << " and " << channels << " channels" << endl;

    size_t num_pixels = img_width * img_height;
    size_t img_size = num_pixels * channels;

    int gray_channels = 1;

    //TODO: Create two uint8_t arrays with the size of the final image
    //TIPS: The first one will be used to store the gray image
    //TIPS: THe second one will be used to store the final image
    uint8_t *gray_scale_image = new uint8_t[img_size];
    uint8_t *output_image = new uint8_t[img_size];

    //TIPS: Weights represents horizontal sobel
    int weights[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    //TIPS: Weights_y represents vertical sobel
    int weights_y[3][3] = {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};

    auto R = sycl::range<1>{9};
    auto I = sycl::range<1>{img_size};
    sycl::buffer filtrox{weights, R}, filtroy{weights_y, R};
    sycl::buffer entrada{gray_scale_image, I}, salida{output_image, I};
    size_t alto = img_height, ancho = img_width;
    auto rango = sycl::range<2>{alto, ancho};
    
    //TIP: Convert the image to gray
    for(unsigned char *p = image, *pg = gray_scale_image; p != image + img_size; p += channels, pg += gray_channels) {
         *pg = (uint8_t)((*p + *(p + 1) + *(p + 2))/3.0);
     }

    int ks = 3; // Kernel size

    double start = omp_get_wtime();

    Q.submit([&](sycl::handler &h){
        sycl::accessor accX(filtrox, h, sycl::read_only);
        sycl::accessor accY(filtroy, h, sycl::read_only);
        sycl::accessor accE(entrada, h, sycl::read_only);
        sycl::accessor accS(salida, h, sycl::write_only);

        h.parallel_for(rango, [=](sycl::id<2> k){
            double sum_x = 0.0;
            double sum_y = 0.0;

            //TIP: Think about the start and end of each index
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {

                    // TODO: Check the boundaries UP, DOWN, LEFT, RIGHT
                    // TIP: Remember that in the top left pixel, for example
                    // we are applying the upper and left part of the kernel
                    // to missing pixels, one approach is ignore it.
                    if(k[1] == 0) {
                        continue; // Up
                    }

                    if(k[1] == img_width - 1) {
                        continue; // Down
                    }

                    if(k[0] == 0) {
                        continue; // left
                    }

                    if(k[0] == img_height - 1) {
                        continue; // right
                    }

                    //TODO: Check the start and end of i and j, 
                    //TODO: get the filter value of each filter
                    int weight = accX[i+1][j+1];
                    int weight_y = accY[i+1][j+1];
                    
                    int original_value = accE[(k[0]+i) * img_width + k[1] + j];
                    sum_x += weight * original_value;
                    sum_y += weight_y * original_value;
                }
            }
            int G = unsigned(std::sqrt(sum_x*sum_x+sum_y*sum_y));
            accS[k[0] * img_width + k[1]] = std::min(G, 255);});     
    });
    Q.wait();
    sycl::host_accessor host_accS(salida, sycl::read_only);

    double end = omp_get_wtime();
    cout << "Time " << end - start << endl;

    const char *nombre;

    if (argc == 3)
        nombre = argv[2];
    else
        nombre = "borders.png";

    stbi_write_png(nombre, img_width, img_height, 1, output_image, 0);

    //Free image
    stbi_image_free(image);
    delete [] output_image;
    delete [] gray_scale_image;

    cout << "Device: " << Q.get_device().get_info<sycl::info::device::name>()<< endl;
    cout << "Vendor: " << Q.get_device().get_info<sycl::info::device::vendor>()<< endl;
    cout << "Version: " << Q.get_device().get_info<sycl::info::device::version>()<< endl;
    cout << "Driver Version: " << Q.get_device().get_info<sycl::info::device::driver_version>()<< endl;

    return 0;
}
