#pragma once

#include <cstdint> 


class Image {
public:
    
    Image(const char* filename);

    
    ~Image();
    bool save(const char* filename);

    
    void grayscale();

   
    int get_width() const { return width; }
    int get_height() const { return height; }
    int get_channels() const { return channels; }
    uint8_t* get_data() const { return data; }

private:
    int width, height, channels;
    size_t size = 0;         
    uint8_t* data = nullptr; 
};

