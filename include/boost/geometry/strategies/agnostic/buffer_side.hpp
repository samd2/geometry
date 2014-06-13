// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2012-2014 Barend Gehrels, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_STRATEGIES_CARTESIAN_BUFFER_SIDE_HPP
#define BOOST_GEOMETRY_STRATEGIES_CARTESIAN_BUFFER_SIDE_HPP

namespace boost { namespace geometry
{

// TODO: consider if this enum can be placed in another headerfile
// or probably there will be more enum's or constants for the buffer
enum buffer_side_selector { buffer_side_left, buffer_side_right };

// Piece type, temporary here, might be reloaced TODO decid this
enum piece_type
{
    buffered_segment, buffered_join, buffered_round_end, buffered_flat_end, buffered_circle
};

}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_STRATEGIES_CARTESIAN_BUFFER_SIDE_HPP
