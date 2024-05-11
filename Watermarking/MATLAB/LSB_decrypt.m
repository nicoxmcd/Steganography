function extracted_watermark = extract_watermark(watermarked_image, key)
    % Read the watermarked image
    watermarked_img = imread("watermarkedLSB_image.png");
    
    % Extract the least significant bit (LSB) where the watermark was embedded
    lsb = bitget(watermarked_img(:,:,1), 1);
    
    % Decrypt the watermark
    decrypted_watermark = xor(lsb, 0201);
    
    % Convert binary image to uint8 for display
    extracted_watermark = uint8(decrypted_watermark * 255);
    
    % Save or display the extracted watermark
    imwrite(extracted_watermark, 'extractedLSB_watermark.png');
end
