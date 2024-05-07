#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Embed secret image in host image using MSB 
void embedImageMSB(Mat &carrier, const Mat &secret) {
    // Both images should be same size and height
    if (carrier.size() != secret.size() || carrier.type() != secret.type()) {
        cout << "Try again :(  \n Both images should be same size and height" << endl;
        return;
    }
    // Iterate over each pixel
    for (int i = 0; i < carrier.rows; i++) {
        for (int j = 0; j < carrier.cols; j++) {
            // Clear the MSB of each pixel in the host image
            carrier.at<uchar>(i, j) &= 0x7F; // 0x7F is 01111111 in binary
            // Set the most significant bit to the MSB of the secret image
            carrier.at<uchar>(i, j) |= (secret.at<uchar>(i, j) & 0x80);
        }
    }
}

int main() {
    // Load the carrier and secret images in grayscale
    Mat carrier = imread("carrier_image.jpg", IMREAD_GRAYSCALE);
    Mat secret = imread("secret_image.jpg", IMREAD_GRAYSCALE);

    if (carrier.empty() || secret.empty()) {
        cout << "Error loading images :(  Check the path to images and file names again!" << endl;
        return -1;
    }

    // Embed the secret image into the carrier
    embedImageMSB(carrier, secret);

    // Save the stego-image
    imwrite("stego_image_msb.jpg", carrier);
  
    cout << "MSB encrypted and saved as stego_image_msb.jpg!" << endl;
    return 0;
}
