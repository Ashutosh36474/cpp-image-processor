#pragma once

#include <cstdint> // Required for fixed-width integer types like uint8_t

/**
 * @class Image
 * @brief Represents an image, handling loading, saving, and processing operations.
 *
 * This class acts as a wrapper around the stb_image libraries, encapsulating
 * the raw pixel data and its properties (width, height, channels).
 */
class Image {
public:
    /**
     * @brief Constructs an Image object by loading an image from a file.
     * @param filename The path to the image file to load.
     */
    Image(const char* filename);

    /**
     * @brief Destructor that frees the memory allocated for the pixel data.
     */
    ~Image();

    /**
     * @brief Saves the current state of the image to a file.
     * @param filename The path where the image will be saved.
     * @return True if saving was successful, false otherwise.
     */
    bool save(const char* filename);

    /**
     * @brief Applies a grayscale filter to the image, modifying its data in place.
     */
    void grayscale();

    // --- Getters ---
    // These methods provide read-only access to the image's private properties.
    int get_width() const { return width; }
    int get_height() const { return height; }
    int get_channels() const { return channels; }
    uint8_t* get_data() const { return data; }

private:
    int width, height, channels;
    size_t size = 0;         // Total number of bytes in the pixel data array.
    uint8_t* data = nullptr; // A pointer to the raw pixel data.
};

