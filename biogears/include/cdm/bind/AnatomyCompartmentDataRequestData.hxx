// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

/**
 * @file
 * @brief Generated from AnatomyCompartmentDataRequestData.xsd.
 */

#ifndef ANATOMY_COMPARTMENT_DATA_REQUEST_DATA_HXX
#define ANATOMY_COMPARTMENT_DATA_REQUEST_DATA_HXX

#ifndef XSD_CXX11
#define XSD_CXX11
#endif

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include "cdm-schema.hxx"

// Forward declarations.
//
namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        class AnatomyCompartmentDataRequestData;
      }
    }
  }
}


#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#include "DataRequestData.hxx"

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        class enumAnatomy;
      }
    }
  }
}

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        class enumCompartmentType;
      }
    }
  }
}

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      /**
       * @brief C++ namespace for the %uri:/mil/tatrc/physiology/datamodel
       * schema namespace.
       */
      namespace datamodel
      {
        /**
         * @brief Class corresponding to the %AnatomyCompartmentDataRequestData schema type.
         *
         * @nosubgrouping
         */
        class __attribute__ ((visibility ("default"))) AnatomyCompartmentDataRequestData: public ::mil::tatrc::physiology::datamodel::DataRequestData
        {
          public:
          /**
           * @name Compartment
           *
           * @brief Accessor and modifier functions for the %Compartment
           * required attribute.
           */
          //@{

          /**
           * @brief Attribute type.
           */
          typedef ::mil::tatrc::physiology::datamodel::enumAnatomy Compartment_type;

          /**
           * @brief Attribute traits type.
           */
          typedef ::xsd::cxx::tree::traits< Compartment_type, char > Compartment_traits;

          /**
           * @brief Return a read-only (constant) reference to the attribute.
           *
           * @return A constant reference to the attribute.
           */
          const Compartment_type&
          Compartment () const;

          /**
           * @brief Return a read-write reference to the attribute.
           *
           * @return A reference to the attribute.
           */
          Compartment_type&
          Compartment ();

          /**
           * @brief Set the attribute value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the attribute.
           */
          void
          Compartment (const Compartment_type& x);

          /**
           * @brief Set the attribute value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly
           * instead of making a copy.
           */
          void
          Compartment (::std::unique_ptr< Compartment_type > p);

          //@}

          /**
           * @name Type
           *
           * @brief Accessor and modifier functions for the %Type
           * required attribute.
           */
          //@{

          /**
           * @brief Attribute type.
           */
          typedef ::mil::tatrc::physiology::datamodel::enumCompartmentType Type_type;

          /**
           * @brief Attribute traits type.
           */
          typedef ::xsd::cxx::tree::traits< Type_type, char > Type_traits;

          /**
           * @brief Return a read-only (constant) reference to the attribute.
           *
           * @return A constant reference to the attribute.
           */
          const Type_type&
          Type () const;

          /**
           * @brief Return a read-write reference to the attribute.
           *
           * @return A reference to the attribute.
           */
          Type_type&
          Type ();

          /**
           * @brief Set the attribute value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the attribute.
           */
          void
          Type (const Type_type& x);

          /**
           * @brief Set the attribute value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly
           * instead of making a copy.
           */
          void
          Type (::std::unique_ptr< Type_type > p);

          //@}

          /**
           * @name Substance
           *
           * @brief Accessor and modifier functions for the %Substance
           * optional attribute.
           */
          //@{

          /**
           * @brief Attribute type.
           */
          typedef ::xml_schema::string Substance_type;

          /**
           * @brief Attribute optional container type.
           */
          typedef ::xsd::cxx::tree::optional< Substance_type > Substance_optional;

          /**
           * @brief Attribute traits type.
           */
          typedef ::xsd::cxx::tree::traits< Substance_type, char > Substance_traits;

          /**
           * @brief Return a read-only (constant) reference to the attribute
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const Substance_optional&
          Substance () const;

          /**
           * @brief Return a read-write reference to the attribute container.
           *
           * @return A reference to the optional container.
           */
          Substance_optional&
          Substance ();

          /**
           * @brief Set the attribute value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the attribute.
           */
          void
          Substance (const Substance_type& x);

          /**
           * @brief Set the attribute value.
           *
           * @param x An optional container with the new value to set.
           *
           * If the value is present in @a x then this function makes a copy 
           * of this value and sets it as the new value of the attribute.
           * Otherwise the attribute container is set the 'not present' state.
           */
          void
          Substance (const Substance_optional& x);

          /**
           * @brief Set the attribute value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          Substance (::std::unique_ptr< Substance_type > p);

          //@}

          /**
           * @name Constructors
           */
          //@{

          /**
           * @brief Default constructor.
           *
           * Note that this constructor leaves required elements and
           * attributes uninitialized.
           */
          AnatomyCompartmentDataRequestData ();

          /**
           * @brief Create an instance from the ultimate base and
           * initializers for required elements and attributes.
           */
          AnatomyCompartmentDataRequestData (const Name_type&,
                                             const Compartment_type&,
                                             const Type_type&);

          /**
           * @brief Create an instance from a DOM element.
           *
           * @param e A DOM element to extract the data from.
           * @param f Flags to create the new instance with.
           * @param c A pointer to the object that will contain the new
           * instance.
           */
          AnatomyCompartmentDataRequestData (const ::xercesc::DOMElement& e,
                                             ::xml_schema::flags f = 0,
                                             ::xml_schema::container* c = 0);

          /**
           * @brief Copy constructor.
           *
           * @param x An instance to make a copy of.
           * @param f Flags to create the copy with.
           * @param c A pointer to the object that will contain the copy.
           *
           * For polymorphic object models use the @c _clone function instead.
           */
          AnatomyCompartmentDataRequestData (const AnatomyCompartmentDataRequestData& x,
                                             ::xml_schema::flags f = 0,
                                             ::xml_schema::container* c = 0);

          /**
           * @brief Copy the instance polymorphically.
           *
           * @param f Flags to create the copy with.
           * @param c A pointer to the object that will contain the copy.
           * @return A pointer to the dynamically allocated copy.
           *
           * This function ensures that the dynamic type of the instance is
           * used for copying and should be used for polymorphic object
           * models instead of the copy constructor.
           */
          virtual AnatomyCompartmentDataRequestData*
          _clone (::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0) const;

          /**
           * @brief Copy assignment operator.
           *
           * @param x An instance to make a copy of.
           * @return A reference to itself.
           *
           * For polymorphic object models use the @c _clone function instead.
           */
          AnatomyCompartmentDataRequestData&
          operator= (const AnatomyCompartmentDataRequestData& x);

          //@}

          /**
           * @brief Destructor.
           */
          virtual 
          ~AnatomyCompartmentDataRequestData ();

          // Implementation.
          //

          //@cond

          protected:
          void
          parse (::xsd::cxx::xml::dom::parser< char >&,
                 ::xml_schema::flags);

          protected:
          ::xsd::cxx::tree::one< Compartment_type > Compartment_;
          ::xsd::cxx::tree::one< Type_type > Type_;
          Substance_optional Substance_;

          //@endcond
        };
      }
    }
  }
}

#include <iosfwd>

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        __attribute__ ((visibility ("default")))
        ::std::ostream&
        operator<< (::std::ostream&, const AnatomyCompartmentDataRequestData&);
      }
    }
  }
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
      }
    }
  }
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace mil
{
  namespace tatrc
  {
    namespace physiology
    {
      namespace datamodel
      {
        __attribute__ ((visibility ("default")))
        void
        operator<< (::xercesc::DOMElement&, const AnatomyCompartmentDataRequestData&);
      }
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
#include "decimal.hxx"

#include "double-parsing.hxx"
#include "decimal-parsing.hxx"

#include "double-serialization.hxx"
#include "decimal-serialization.hxx"
//
// End epilogue.

#endif // ANATOMY_COMPARTMENT_DATA_REQUEST_DATA_HXX