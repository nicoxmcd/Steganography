#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Function to embed one image into another using LSB
void embedImage(Mat &carrier, const Mat &secret) {
    // Ensure both images are of the same size and type
    if (carrier.size() != secret.size() || carrier.type() != secret.type()) {
        cout << "Images must be of the same size and type. Check file size and type." << endl;
        return;
    }

    // Iterate over each pixel
    for (int i = 0; i < carrier.rows; i++) {
        for (int j = 0; j < carrier.cols; j++) {
            // Clear the least significant bit of each pixel in the carrier image
            carrier.at<uchar>(i, j) &= 0xFE; // 0xFE is 11111110 in binary
            // Set the least significant bit to the most significant bit of the secret image
            carrier.at<uchar>(i, j) |= (secret.at<uchar>(i, j) >> 7);
        }
    }
}

int main() {
    // Load the carrier and secret images in grayscale
    Mat carrier = imread("carrier_image.jpg", IMREAD_GRAYSCALE);
    Mat secret = imread("secret_image.jpg", IMREAD_GRAYSCALE);

    if (carrier.empty() || secret.empty()) {
        cout << "Error loading images, check file and path names again!" << endl;
        return -1;
    }

    // Embed the secret image into the carrier
    embedImage(carrier, secret);

    // Save the stego-image
    imwrite("LSB_encrypted.jpg", carrier);


    cout << "LSB encryption completed and saved as LSB_encrypted.jpg!" << endl;
    return 0;
}
