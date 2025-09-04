#include <iostream>
#include <string>
#include "Image.h"

// The main function is the entry point for the application.
// argc holds the count of command-line arguments, and argv is an array of them.
int main(int argc, char* argv[]) {
    // The program expects exactly 4 arguments:
    // 1. The program name itself (e.g., ./image_processor)
    // 2. The input file path
    // 3. The output file path
    // 4. The filter name
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file> <filter>" << std::endl;
        std::cerr << "Example: " << argv[0] << " images/cat.jpg images/cat_gray.png grayscale" << std::endl;
        return 1; // Indicate an error
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string filterType = argv[3];

    // Create an Image object. The constructor will handle loading the file.
    Image image(inputFile.c_str());
    if (image.get_data() == nullptr) {
        std::cerr << "Error: Could not load image from " << inputFile << std::endl;
        return 1;
    }

    // Check which filter was requested and call the corresponding method.
    if (filterType == "grayscale") {
        image.grayscale();
    } else {
        std::cerr << "Error: Unknown filter type '" << filterType << "'. Available filters: grayscale" << std::endl;
        return 1;
    }

    // Attempt to save the modified image data.
    if (image.save(outputFile.c_str())) {
        std::cout << "Successfully applied filter and saved image to " << outputFile << std::endl;
    } else {
        std::cerr << "Error: Could not save image to " << outputFile << std::endl;
        return 1;
    }

    return 0; // Indicate success
}

