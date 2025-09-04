#include "Image.h"
#include <cmath> // Required for std::round used in the grayscale formula

// These preprocessor directives are essential. They instruct the stb library
// headers to include the actual C implementation code. This must be done
// in exactly one .cpp file in the entire project to avoid linker errors.
#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "vendor/stb_image_write.h"

Image::Image(const char* filename) {
    // stbi_load() attempts to load an image from the specified file.
    // It allocates memory for the pixels and returns a pointer to it.
    // On failure, it returns nullptr.
    // The width, height, and channels arguments are passed by reference and
    // are filled in by the function.
    data = stbi_load(filename, &width, &height, &channels, 0);
    if (data != nullptr) {
        // Calculate the total size of the data buffer in bytes.
        size = width * height * channels;
    }
}

Image::~Image() {
    // It's crucial to free the memory allocated by stbi_load to prevent memory leaks.
    stbi_image_free(data);
}

bool Image::save(const char* filename) {
    // For simplicity, we save the output as a PNG file.
    // stbi_write_png() takes the filename, dimensions, channels, data,
    // and stride (bytes per row). It returns a non-zero value on success.
    return stbi_write_png(filename, width, height, channels, data, width * channels) != 0;
}

void Image::grayscale() {
    // The grayscale conversion is only applicable to color images (3 or 4 channels).
    if (channels < 3) {
        return;
    }

    // Iterate through the pixel data array. Each pixel consists of 'channels'
    // consecutive bytes (e.g., R, G, B). We increment the loop counter by
    // 'channels' to jump from the start of one pixel to the start of the next.
    for (int i = 0; i < size; i += channels) {
        // Extract the Red, Green, and Blue values for the current pixel.
        uint8_t r = data[i];
        uint8_t g = data[i + 1];
        uint8_t b = data[i + 2];

        // Calculate the grayscale value using the standard luminosity formula,
        // which weights the colors according to human perception.
        uint8_t gray = static_cast<uint8_t>(std::round(0.299 * r + 0.587 * g + 0.114 * b));

        // Overwrite the original Red, Green, and Blue values with the new gray value.
        data[i] = gray;
        data[i + 1] = gray;
        data[i + 2] = gray;
    }
}

