#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Embed secret image in host image using MSB 
void embedImageMSB(Mat &host, const Mat &secret) {
    // Both images should be same size and height
    if (host.size() != secret.size() || host.type() != secret.type()) {
        cout << "Try again :(  \n Both images should be same size and height" << endl;
        return;
    }
    // Iterate over each pixel
    for (int i = 0; i < host.rows; i++) {
        for (int j = 0; j < host.cols; j++) {
            // Clear the MSB of each pixel in the host image
            host.at<uchar>(i, j) &= 0x7F; // 0x7F is 01111111 in binary
            // Set the most significant bit to the MSB of the secret image
            host.at<uchar>(i, j) |= (secret.at<uchar>(i, j) & 0x80);
        }
    }
}

int main() {
    // Load the host and secret images in grayscale
    Mat host = imread("src/banana.jpg", IMREAD_GRAYSCALE);
    Mat secret = imread("src/train.jpg", IMREAD_GRAYSCALE);

    if (host.empty() || secret.empty()) {
        cout << "Error loading images :(  Check the path to images and file names again!" << endl;
        return -1;
    }

    // Embed the secret image into the host
    embedImageMSB(host, secret);

    // Save the stego-image
    imwrite("MSB_encrypted.jpg", host);
  
    cout << "MSB encrypted and saved as MSB_encrypted.jpg!" << endl;
    return 0;
}
