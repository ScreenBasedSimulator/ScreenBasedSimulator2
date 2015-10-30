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
 * @brief Generated from enumPatientAssessment.xsd.
 */

#ifndef ENUM_PATIENT_ASSESSMENT_HXX
#define ENUM_PATIENT_ASSESSMENT_HXX

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
        class enumPatientAssessment;
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
         * @brief Enumeration class corresponding to the %enumPatientAssessment
         * schema type.
         */
        class __attribute__ ((visibility ("default"))) enumPatientAssessment: public ::xml_schema::string
        {
          public:

          /**
           * @brief Underlying enum type.
           */
          enum value
          {
            PulmonaryFunctionTest,
            CompleteBloodCount,
            CompleteMetabolicPanel,
            Urinalysis
          };

          /**
           * @brief Default constructor.
           *
           * Note that this constructor may leave the instance in an
           * invalid state.
           */
          enumPatientAssessment ();

          /**
           * @brief Create an instance from the underlying enum value.
           *
           * @param v A enum value.
           */
          enumPatientAssessment (value v);

          /**
           * @brief Create an instance from a C string.
           *
           * @param v A string value.
           */
          enumPatientAssessment (const char* v);

          /**
           * @brief Create an instance from a string.
           *
           * @param v A string value.
           */
          enumPatientAssessment (const ::std::string& v);

          /**
           * @brief Create an instance from the base value.
           *
           * @param v A base value.
           */
          enumPatientAssessment (const ::xml_schema::string& v);

          /**
           * @brief Create an instance from a DOM element.
           *
           * @param e A DOM element to extract the data from.
           * @param f Flags to create the new instance with.
           * @param c A pointer to the object that will contain the new
           * instance.
           */
          enumPatientAssessment (const ::xercesc::DOMElement& e,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

          /**
           * @brief Create an instance from a DOM attribute.
           *
           * @param a A DOM attribute to extract the data from.
           * @param f Flags to create the new instance with.
           * @param c A pointer to the object that will contain the new
           * instance.
           */
          enumPatientAssessment (const ::xercesc::DOMAttr& a,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

          /**
           * @brief Create an instance from a string fragment.
           *
           * @param s A string fragment to extract the data from.
           * @param e A pointer to DOM element containing the string fragment.
           * @param f Flags to create the new instance with.
           * @param c A pointer to the object that will contain the new
           * instance.
           */
          enumPatientAssessment (const ::std::string& s,
                                 const ::xercesc::DOMElement* e,
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
          enumPatientAssessment (const enumPatientAssessment& x,
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
          virtual enumPatientAssessment*
          _clone (::xml_schema::flags f = 0,
                  ::xml_schema::container* c = 0) const;

          /**
           * @brief Assign the underlying enum value.
           *
           * @param v A enum value.
           * @return A refernce to the instance.
           */
          enumPatientAssessment&
          operator= (value v);

          /**
           * @brief Implicit conversion operator to the underlying
           * enum value.
           *
           * @return A enum value.
           */
          virtual
          operator value () const
          {
            return _xsd_enumPatientAssessment_convert ();
          }

          //@cond

          protected:
          value
          _xsd_enumPatientAssessment_convert () const;

          public:
          static const char* const _xsd_enumPatientAssessment_literals_[4];
          static const value _xsd_enumPatientAssessment_indexes_[4];

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
        operator<< (::std::ostream&, enumPatientAssessment::value);

        __attribute__ ((visibility ("default")))
        ::std::ostream&
        operator<< (::std::ostream&, const enumPatientAssessment&);
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
        operator<< (::xercesc::DOMElement&, const enumPatientAssessment&);

        __attribute__ ((visibility ("default")))
        void
        operator<< (::xercesc::DOMAttr&, const enumPatientAssessment&);

        __attribute__ ((visibility ("default")))
        void
        operator<< (::xml_schema::list_stream&,
                    const enumPatientAssessment&);
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

#endif // ENUM_PATIENT_ASSESSMENT_HXX