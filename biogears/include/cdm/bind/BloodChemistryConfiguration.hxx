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
 * @brief Generated from BloodChemistryConfiguration.xsd.
 */

#ifndef BLOOD_CHEMISTRY_CONFIGURATION_HXX
#define BLOOD_CHEMISTRY_CONFIGURATION_HXX

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
        class BloodChemistryConfiguration;
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
      namespace datamodel
      {
        class ScalarMassPerAmountData;
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
        class ScalarVolumeData;
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
        class ScalarLengthData;
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
        class ScalarAreaPerTimePerPressureData;
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
         * @brief Class corresponding to the %BloodChemistryConfiguration schema type.
         *
         * @nosubgrouping
         */
        class __attribute__ ((visibility ("default"))) BloodChemistryConfiguration: public ::xml_schema::type
        {
          public:
          /**
           * @name MeanCorpuscularHemoglobin
           *
           * @brief Accessor and modifier functions for the %MeanCorpuscularHemoglobin
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarMassPerAmountData MeanCorpuscularHemoglobin_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< MeanCorpuscularHemoglobin_type > MeanCorpuscularHemoglobin_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< MeanCorpuscularHemoglobin_type, char > MeanCorpuscularHemoglobin_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const MeanCorpuscularHemoglobin_optional&
          MeanCorpuscularHemoglobin () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          MeanCorpuscularHemoglobin_optional&
          MeanCorpuscularHemoglobin ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          MeanCorpuscularHemoglobin (const MeanCorpuscularHemoglobin_type& x);

          /**
           * @brief Set the element value.
           *
           * @param x An optional container with the new value to set.
           *
           * If the value is present in @a x then this function makes a copy 
           * of this value and sets it as the new value of the element.
           * Otherwise the element container is set the 'not present' state.
           */
          void
          MeanCorpuscularHemoglobin (const MeanCorpuscularHemoglobin_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          MeanCorpuscularHemoglobin (::std::unique_ptr< MeanCorpuscularHemoglobin_type > p);

          //@}

          /**
           * @name MeanCorpuscularVolume
           *
           * @brief Accessor and modifier functions for the %MeanCorpuscularVolume
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarVolumeData MeanCorpuscularVolume_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< MeanCorpuscularVolume_type > MeanCorpuscularVolume_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< MeanCorpuscularVolume_type, char > MeanCorpuscularVolume_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const MeanCorpuscularVolume_optional&
          MeanCorpuscularVolume () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          MeanCorpuscularVolume_optional&
          MeanCorpuscularVolume ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          MeanCorpuscularVolume (const MeanCorpuscularVolume_type& x);

          /**
           * @brief Set the element value.
           *
           * @param x An optional container with the new value to set.
           *
           * If the value is present in @a x then this function makes a copy 
           * of this value and sets it as the new value of the element.
           * Otherwise the element container is set the 'not present' state.
           */
          void
          MeanCorpuscularVolume (const MeanCorpuscularVolume_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          MeanCorpuscularVolume (::std::unique_ptr< MeanCorpuscularVolume_type > p);

          //@}

          /**
           * @name StandardDiffusionDistance
           *
           * @brief Accessor and modifier functions for the %StandardDiffusionDistance
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarLengthData StandardDiffusionDistance_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< StandardDiffusionDistance_type > StandardDiffusionDistance_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< StandardDiffusionDistance_type, char > StandardDiffusionDistance_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const StandardDiffusionDistance_optional&
          StandardDiffusionDistance () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          StandardDiffusionDistance_optional&
          StandardDiffusionDistance ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          StandardDiffusionDistance (const StandardDiffusionDistance_type& x);

          /**
           * @brief Set the element value.
           *
           * @param x An optional container with the new value to set.
           *
           * If the value is present in @a x then this function makes a copy 
           * of this value and sets it as the new value of the element.
           * Otherwise the element container is set the 'not present' state.
           */
          void
          StandardDiffusionDistance (const StandardDiffusionDistance_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          StandardDiffusionDistance (::std::unique_ptr< StandardDiffusionDistance_type > p);

          //@}

          /**
           * @name StandardOxygenDiffusionCoefficient
           *
           * @brief Accessor and modifier functions for the %StandardOxygenDiffusionCoefficient
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarAreaPerTimePerPressureData StandardOxygenDiffusionCoefficient_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< StandardOxygenDiffusionCoefficient_type > StandardOxygenDiffusionCoefficient_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< StandardOxygenDiffusionCoefficient_type, char > StandardOxygenDiffusionCoefficient_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const StandardOxygenDiffusionCoefficient_optional&
          StandardOxygenDiffusionCoefficient () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          StandardOxygenDiffusionCoefficient_optional&
          StandardOxygenDiffusionCoefficient ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          StandardOxygenDiffusionCoefficient (const StandardOxygenDiffusionCoefficient_type& x);

          /**
           * @brief Set the element value.
           *
           * @param x An optional container with the new value to set.
           *
           * If the value is present in @a x then this function makes a copy 
           * of this value and sets it as the new value of the element.
           * Otherwise the element container is set the 'not present' state.
           */
          void
          StandardOxygenDiffusionCoefficient (const StandardOxygenDiffusionCoefficient_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          StandardOxygenDiffusionCoefficient (::std::unique_ptr< StandardOxygenDiffusionCoefficient_type > p);

          //@}

          /**
           * @name Constructors
           */
          //@{

          /**
           * @brief Create an instance from the ultimate base and
           * initializers for required elements and attributes.
           */
          BloodChemistryConfiguration ();

          /**
           * @brief Create an instance from a DOM element.
           *
           * @param e A DOM element to extract the data from.
           * @param f Flags to create the new instance with.
           * @param c A pointer to the object that will contain the new
           * instance.
           */
          BloodChemistryConfiguration (const ::xercesc::DOMElement& e,
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
          BloodChemistryConfiguration (const BloodChemistryConfiguration& x,
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
          virtual BloodChemistryConfiguration*
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
          BloodChemistryConfiguration&
          operator= (const BloodChemistryConfiguration& x);

          //@}

          /**
           * @brief Destructor.
           */
          virtual 
          ~BloodChemistryConfiguration ();

          // Implementation.
          //

          //@cond

          protected:
          void
          parse (::xsd::cxx::xml::dom::parser< char >&,
                 ::xml_schema::flags);

          protected:
          MeanCorpuscularHemoglobin_optional MeanCorpuscularHemoglobin_;
          MeanCorpuscularVolume_optional MeanCorpuscularVolume_;
          StandardDiffusionDistance_optional StandardDiffusionDistance_;
          StandardOxygenDiffusionCoefficient_optional StandardOxygenDiffusionCoefficient_;

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
        operator<< (::std::ostream&, const BloodChemistryConfiguration&);
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
        operator<< (::xercesc::DOMElement&, const BloodChemistryConfiguration&);
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

#endif // BLOOD_CHEMISTRY_CONFIGURATION_HXX