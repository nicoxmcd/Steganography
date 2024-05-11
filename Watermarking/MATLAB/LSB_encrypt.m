function watermarked_image = embed_watermark(original_image, watermark_image, key)
    % Read the original and watermark images
    orig_img = imread("duck.jpg");
    watermark = imread("stevens.png");
    
    % Resize watermark to match the original image size
    watermark = imresize(watermark, size(orig_img(:,:,1)));
    
    % Check if the watermark image is RGB, and convert it to grayscale
    if size(watermark, 3) == 3
        watermark_gray = rgb2gray(watermark);
    else
        watermark_gray = watermark; % If the image is already in grayscale
    end

    % Convert watermark to binary
    watermark_bin = imbinarize(watermark_gray);
    
    % Encrypt the watermark using a simple XOR operation
    encrypted_watermark = xor(watermark_bin, 0201);
    
    % Embed the encrypted watermark into the original image
    watermarkedLSB_image = orig_img;
    watermarkedLSB_image(:,:,1) = bitset(watermarkedLSB_image(:,:,1), 1, encrypted_watermark);
    
    % Save the watermarked image
    imwrite(watermarkedLSB_image, 'watermarkedLSB_image.png');
end
