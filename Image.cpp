#include "Image.h"
#include <cmath> 
#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "vendor/stb_image_write.h"

Image::Image(const char* filename) {

    data = stbi_load(filename, &width, &height, &channels, 0);
    if (data != nullptr) {
        size = width * height * channels;
    }
}

Image::~Image() {
    
    stbi_image_free(data);
}

bool Image::save(const char* filename) {
    
    return stbi_write_png(filename, width, height, channels, data, width * channels) != 0;
}

void Image::grayscale() {
    
    if (channels < 3) {
        return;
    }

   
    for (int i = 0; i < size; i += channels) {
        
        uint8_t r = data[i];
        uint8_t g = data[i + 1];
        uint8_t b = data[i + 2];

      
        uint8_t gray = static_cast<uint8_t>(std::round(0.299 * r + 0.587 * g + 0.114 * b));
        data[i] = gray;
        data[i + 1] = gray;
        data[i + 2] = gray;
    }
}

