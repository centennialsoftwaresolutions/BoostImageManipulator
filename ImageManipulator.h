#include <boost/gil.hpp>
#include <boost/gil/extension/dynamic_image/any_image.hpp>
#include <boost/gil/extension/io/jpeg.hpp>
#include <boost/mp11.hpp>
#include <boost/gil/extension/io/jpeg.hpp>
#include <boost/gil/extension/numeric/sampler.hpp>
#include <boost/gil/extension/numeric/resample.hpp>
#include <string>
#include <iostream>
#include <stdexcept>

namespace bg = boost::gil;

class ImageManipulator {
    public:
      std::string image_fpath;

      ImageManipulator(std::string image_fpath);
      void resize_image(int height, int width);
      void crop_image(int bottom, int left, int height, int width);
      auto get_usr_input_img_width();
      auto get_usr_input_img_height();
    private:
      bg::rgb8_image_t usr_input_img;
      /* would love for this to be generic at some point*/
      // bg::any_image<bg::gray8_image_t, bg::rgb8_image_t, bg::gray16_image_t, bg::rgb16_image_t> usr_input_img;

};
