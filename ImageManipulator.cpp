#include <ImageManipulator.h>


ImageManipulator::ImageManipulator(std::string image_fpath)
{
    this->image_fpath = image_fpath;
    bg::read_image(this->image_fpath, this->usr_input_img, bg::jpeg_tag{});
    this->img_height = this->usr_input_img.height();
    this->img_width = this->usr_input_img.width();
}


bg::rgb8_image_t ImageManipulator::resize_image(int width, int height)
{
    bg::rgb8_image_t resize_square(width, height);
    bg::resize_view(bg::const_view(usr_input_img), bg::view(resize_square), bg::bilinear_sampler());
    bg::write_view("output.jpg", bg::const_view(resize_square), bg::jpeg_tag{});
    return resize_square;
}


void ImageManipulator::crop_image(int top, int left, int width, int height)
{
    bg::rgb8c_view_t cropped_img;
    bg::point_t top_left_point(top, left);
    bg::point_t dimensions(width, height);
    cropped_img = bg::subimage_view(bg::const_view(this->usr_input_img), top_left_point, dimensions);
    bg::write_view("output.jpg", cropped_img, bg::jpeg_tag{});
}


void ImageManipulator::blur_image()
{
    bg::rgb8_image_t orig_image = this->usr_input_img;
    auto small_square = resize_image(this->img_width/5, this->img_height/5);
    this->usr_input_img = small_square;
    resize_image(orig_image.width(), orig_image.height());
    this->usr_input_img = orig_image;
}


long int ImageManipulator::get_usr_input_img_height()
{
    return this->img_height;
}


long int ImageManipulator::get_usr_input_img_width()
{
    return this->img_width;
}
