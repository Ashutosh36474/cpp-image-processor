#include <iostream>
#include <string>
#include "Image.h"

int main(int argc, char* argv[]) {
   
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> <filter>" << std::endl;
        std::cerr << "Example: " << argv[0] << " images/cat.jpg images/cat_gray.png grayscale" << std::endl;
        return 1; 
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string filterType = argv[3];

   
    Image image(inputFile.c_str());
    if (image.get_data() == nullptr) {
        std::cerr << "Error: Could not load image from " << inputFile << std::endl;
        return 1;
    }


    if (filterType == "grayscale") {
        image.grayscale();
    } else {
        std::cerr << "Error: Unknown filter type '" << filterType << "'. Available filters: grayscale" << std::endl;
        return 1;
    }


    if (image.save(outputFile.c_str())) {
        std::cout << "Successfully applied filter and saved image to " << outputFile << std::endl;
    } else {
        std::cerr << "Error: Could not save image to " << outputFile << std::endl;
        return 1;
    }

    return 0; 
}

