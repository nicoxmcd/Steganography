
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Extract hidden image from the carrier using MSB
Mat extractImageMSB(const Mat &carrier, int width, int height) {
    Mat extracted(Size(width, height), CV_8UC1);

    // Taking MSB of each pixel
    for (int i = 0; i < carrier.rows; i++) {
        for (int j = 0; j < carrier.cols; j++) {
            extracted.at<uchar>(i, j) = (carrier.at<uchar>(i, j) & 0x80) ? 255 : 0;
        }
    }

    return extracted;
}

int main() {
    // Load the carrier and secret images in grayscale
    Mat carrier = imread("carrier_image.jpg", IMREAD_GRAYSCALE);
    Mat secret = imread("secret_image.jpg", IMREAD_GRAYSCALE);

    if (carrier.empty() || secret.empty()) {
        cout << "Error loading images!" << endl;
        return -1;
    }

    // Extract the secret image 
    Mat extracted = extractImageMSB(carrier, carrier.cols, carrier.rows);
    imwrite("extracted_image_msb.jpg", extracted);

    cout << "MSB .jpg  Decrypted" << endl;
    return 0;
}
