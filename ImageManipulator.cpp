#include <boost/gil.hpp>
#include <boost/gil/extension/io/jpeg.hpp>
#include <boost/gil/extension/numeric/sampler.hpp>
#include <boost/gil/extension/numeric/resample.hpp>
#include <iostream>
#include <ImageManipulator.h>

ImageManipulator::ImageManipulator(std::string image_fpath) {
    this->image_fpath = image_fpath;
    bg::read_image(this->image_fpath, this->usr_input_img, bg::jpeg_tag{});
}

void ImageManipulator::resize_image(int height, int width) {
    bg::rgb8_image_t resize_square(height, width);
    bg::read_image(image_fpath, this->usr_input_img, bg::jpeg_tag{});
    bg::resize_view(bg::const_view(usr_input_img), bg::view(resize_square), bg::bilinear_sampler());
    bg::write_view("output.jpg", bg::const_view(usr_input_img), bg::jpeg_tag{});
}
void ImageManipulator::crop_image() {
    return;
}


int main(int argc, char *argv[])
{

    return 0;
}

