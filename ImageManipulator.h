#include <boost/gil.hpp>
#include <boost/gil/extension/io/jpeg.hpp>
#include <boost/gil/extension/numeric/sampler.hpp>
#include <boost/gil/extension/numeric/resample.hpp>
// #include <boost/gil/extension/dynamic_image/any_image.hpp>
#include <string>
#include <iostream>
#include <ios>
#include <stdexcept>

namespace bg = boost::gil;

class ImageManipulator {
    public:
      std::string image_fpath;

      ImageManipulator(std::string image_fpath);
      bg::rgb8_image_t resize_image(int height, int width);
      void crop_image(int bottom, int left, int height, int width);
      void blur_image();
      long int get_usr_input_img_width();
      long int get_usr_input_img_height();
    private:
      bg::rgb8_image_t usr_input_img;
      int img_height;
      int img_width;
      /* would like for this to be more generic at some point*/
      // bg::any_image<bg::gray8_image_t, bg::rgb8_image_t, bg::gray16_image_t, bg::rgb16_image_t> usr_input_img;

};
