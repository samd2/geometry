// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2014-2015, Oracle and/or its affiliates.

// Contributed and/or modified by Menelaos Karavelas, on behalf of Oracle

// Licensed under the Boost Software License version 1.0.
// http://www.boost.org/users/license.html

#ifndef BOOST_GEOMETRY_ALGORITHMS_DETAIL_IS_VALID_HAS_DUPLICATES_HPP
#define BOOST_GEOMETRY_ALGORITHMS_DETAIL_IS_VALID_HAS_DUPLICATES_HPP

#include <boost/range.hpp>

#include <boost/geometry/core/closure.hpp>

#include <boost/geometry/policies/compare.hpp>
#include <boost/geometry/policies/is_valid/null_policy.hpp>

#include <boost/geometry/views/closeable_view.hpp>
#include <boost/geometry/algorithms/validity_failure_type.hpp>


namespace boost { namespace geometry
{


#ifndef DOXYGEN_NO_DETAIL
namespace detail { namespace is_valid
{

template <typename Range, closure_selector Closure>
struct has_duplicates
{
    template <typename VisitPolicy>
    static inline bool apply(Range const& range, VisitPolicy& visitor)
    {
        typedef typename closeable_view<Range const, Closure>::type view_type;
        typedef typename boost::range_iterator<view_type const>::type iterator;

        view_type view(range);

        if ( boost::size(view) < 2 )
        {
            visitor.template apply<no_failure>();
            return false;
        }

        geometry::equal_to<typename boost::range_value<Range>::type> equal;

        iterator it = boost::begin(view);
        iterator next = ++boost::begin(view);
        for (; next != boost::end(view); ++it, ++next)
        {
            if ( equal(*it, *next) )
            {
                visitor.template apply<failure_duplicate_points>(*it);
                return true;
            }
        }
        visitor.template apply<no_failure>();
        return false;
    }

    // needed by the is_simple algorithm
    static inline bool apply(Range const& range)
    {
        is_valid_null_policy visitor;
        return apply(range, visitor);
    }
};



}} // namespace detail::is_valid
#endif // DOXYGEN_NO_DETAIL


}} // namespace boost::geometry



#endif // BOOST_GEOMETRY_ALGORITHMS_DETAIL_IS_VALID_HAS_DUPLICATES_HPP
