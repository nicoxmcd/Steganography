#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Function to embed one image into another using LSB
void embedImage(Mat &host, const Mat &secret) {
    // Ensure both images are of the same size and type
    if (host.size() != secret.size() || host.type() != secret.type()) {
        cout << "Images must be of the same size and type. Check file size and type." << endl;
        return;
    }
    // Iterate over each pixel
    for (int i = 0; i < host.rows; i++) {
        for (int j = 0; j < host.cols; j++) {
            // Clear the least significant bit of each pixel in the host image
            host.at<uchar>(i, j) &= 0xFE; // 0xFE is 11111110 in binary
            // Set the least significant bit to the most significant bit of the secret image
            host.at<uchar>(i, j) |= (secret.at<uchar>(i, j) >> 7);
        }
    }
}



int main() {
    // Load the host and secret images in grayscale
    string host_choice, secret_choice;

    string choice[10] = {"banana.jpg", "cat.jpg", "cockatiel.jpg", "forest.jpg", "gold.jpg", "monkey.jpg", "plane.jpg", "sashimi.jpg", "secret_message.jpg", "train.jpg"};
 
    cout << "Hello, in this program we will be encrypting a secret image into a host image using LSB technique." << endl;
    cout << "" << endl;

    // for (int i = 0; i < (sizeof(choice)/sizeof(choice[0])); i++) {
    //     cout << "[" << i << "]" << choice[i] << endl;
    // }
    // bool valid = false;
    // while(valid){
    //     cout << "Choose the number of the image provided for the HOST image: ";
    //     cin >> host_choice;
    //     // Switch case to set the host image to grayscale
    //     switch (host_choice) {
    //     case 0:
    //         Mat host = imread(choice[0], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 1:
    //         Mat host = imread(choice[1], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 2:
    //         Mat host = imread(choice[2], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 3:
    //         Mat host = imread(choice[3], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 4:
    //         Mat host = imread(choice[4], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 5:
    //         Mat host = imread(choice[5], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 6:
    //         Mat host = imread(choice[6], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 7:
    //         Mat host = imread(choice[7], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 8:
    //         Mat host = imread(choice[8], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 9:
    //         Mat host = imread(choice[9], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     case 10:
    //         Mat host = imread(choice[10], IMREAD_GRAYSCALE);
    //         valid = true;
    //         break;
    //     default:
    //         cout << "Enter a valid number." << endl;
    //     }
    // }

    // for (int i = 0; i < (sizeof(choice)/sizeof(choice[0])); i++) {
    //     if(host_choice == choice[i]){
    //         break;
    //     }
    //     else if (host_choice != choice[(sizeof(choice)/sizeof(choice[0]))]) {
    //         cout << "Please choose a valid name." << endl;
    //     }
    // }


    // for (int i = 0; i < (sizeof(choice)/sizeof(choice[0])); i++) {
    //     if(host_choice == choice[i]){

    //     }
    // }
    // for x in choice:
    //     if host_choice == x {
    //         choice.remove(host_choice);
    //     }
    
    // cout << "Please choose an image provided for the SECRET image:" << endl;
    // cout << "" << endl;
    Mat host = imread("src/banana.jpg", IMREAD_GRAYSCALE);
    Mat secret = imread("src/train.jpg", IMREAD_GRAYSCALE);

    if (host.empty() || secret.empty()) {
        cout << "Error loading images, check file and path names again!" << endl;
        return -1;
    }

    // Embed the secret image into the host using OpenCV
    embedImage(host, secret);
    // Save the stego-image
    imwrite("LSB_encrypted.jpg", host);
    cout << "LSB encryption completed and saved as LSB_encrypted.jpg!" << endl;
    return 0;
}
