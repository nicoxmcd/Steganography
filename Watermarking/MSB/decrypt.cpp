#include <opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Extract hidden image from the encrypted using MSB
Mat extractImageMSB(const Mat &encrypted, int width, int height) {
    Mat extracted(Size(width, height), CV_8UC1);

    // Taking MSB of each pixel
    for (int i = 0; i < encrypted.rows; i++) {
        for (int j = 0; j < encrypted.cols; j++) {
            extracted.at<uchar>(i, j) = (encrypted.at<uchar>(i, j) & 0x80) ? 255 : 0;
        }
    }

    return extracted;
}

int main() {
    // Load the encrypted and secret images in grayscale
    Mat encrypted = imread("MSB_encrypted.jpg", IMREAD_GRAYSCALE);

    if (encrypted.empty()) {
        cout << "Error loading image! Check file and path name again!" << endl;
        return -1;
    }

    // Extract the secret image 
    Mat extracted = extractImageMSB(encrypted, encrypted.cols, encrypted.rows);
    imwrite("extracted_image_msb.jpg", extracted);

    cout << "MSB decrypted and saved as extracted_image_msb.jpg" << endl;
    return 0;
}
