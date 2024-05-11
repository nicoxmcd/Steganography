#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Function to extract the hidden image from the encrypted
Mat extractImage(const Mat &encrypted, int width, int height) {
    Mat extracted(Size(width, height), CV_8UC1);

    // Extracting the LSB of each pixel
    for (int i = 0; i < encrypted.rows; i++) {
        for (int j = 0; j < encrypted.cols; j++) {
            extracted.at<uchar>(i, j) = (encrypted.at<uchar>(i, j) & 0x01) << 7;
        }
    }

    return extracted;
}

int main() {
    Mat encrypted = imread("LSB_encrypted.jpg", IMREAD_GRAYSCALE);

    if (encrypted.empty()) {
        cout << "Error loading image, check file and path name again!" << endl;
        return -1;
    }

    // Optionally, extract the image to verify
    Mat extracted = extractImage(encrypted, encrypted.cols, encrypted.rows);
    imwrite("LSB_extracted.jpg", extracted);

    cout << "LSB decryption completed and saved as LSB_extracted.jpg!" << endl;
    return 0;
}

