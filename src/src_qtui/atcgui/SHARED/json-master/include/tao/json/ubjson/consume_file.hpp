// Copyright (c) 2018-2020 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAO_JSON_UBJSON_CONSUME_FILE_HPP
#define TAO_JSON_UBJSON_CONSUME_FILE_HPP

#include <filesystem>

#include "../external/pegtl/file_input.hpp"

#include "../consume.hpp"
#include "../forward.hpp"

#include "parts_parser.hpp"

namespace tao::json::ubjson
{
   template< typename T, template< typename... > class Traits = traits >
   [[nodiscard]] T consume_file( const std::filesystem::path& path )
   {
      ubjson::basic_parts_parser< 1 << 24, utf8_mode::check, pegtl::file_input< pegtl::tracking_mode::lazy > > pp( path );
      return json::consume< T, Traits >( pp );
   }

   template< template< typename... > class Traits = traits, typename T >
   void consume_file( const std::filesystem::path& path, T& t )
   {
      ubjson::basic_parts_parser< 1 << 24, utf8_mode::check, pegtl::file_input< pegtl::tracking_mode::lazy > > pp( path );
      json::consume< Traits >( pp, t );
   }

}  // namespace tao::json::ubjson

#endif
