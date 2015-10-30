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
 * @brief Generated from GastrointestinalConfiguration.xsd.
 */

#ifndef GASTROINTESTINAL_CONFIGURATION_HXX
#define GASTROINTESTINAL_CONFIGURATION_HXX

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
        class GastrointestinalConfiguration;
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
        class ScalarFractionData;
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
        class ScalarMassPerTimeData;
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
        class NutritionData;
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
        class ScalarVolumePerTimeData;
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
         * @brief Class corresponding to the %GastrointestinalConfiguration schema type.
         *
         * @nosubgrouping
         */
        class __attribute__ ((visibility ("default"))) GastrointestinalConfiguration: public ::xml_schema::type
        {
          public:
          /**
           * @name CalciumAbsorbtionFraction
           *
           * @brief Accessor and modifier functions for the %CalciumAbsorbtionFraction
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarFractionData CalciumAbsorbtionFraction_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< CalciumAbsorbtionFraction_type > CalciumAbsorbtionFraction_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< CalciumAbsorbtionFraction_type, char > CalciumAbsorbtionFraction_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const CalciumAbsorbtionFraction_optional&
          CalciumAbsorbtionFraction () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          CalciumAbsorbtionFraction_optional&
          CalciumAbsorbtionFraction ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          CalciumAbsorbtionFraction (const CalciumAbsorbtionFraction_type& x);

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
          CalciumAbsorbtionFraction (const CalciumAbsorbtionFraction_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          CalciumAbsorbtionFraction (::std::unique_ptr< CalciumAbsorbtionFraction_type > p);

          //@}

          /**
           * @name CalciumDigestionRate
           *
           * @brief Accessor and modifier functions for the %CalciumDigestionRate
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarMassPerTimeData CalciumDigestionRate_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< CalciumDigestionRate_type > CalciumDigestionRate_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< CalciumDigestionRate_type, char > CalciumDigestionRate_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const CalciumDigestionRate_optional&
          CalciumDigestionRate () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          CalciumDigestionRate_optional&
          CalciumDigestionRate ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          CalciumDigestionRate (const CalciumDigestionRate_type& x);

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
          CalciumDigestionRate (const CalciumDigestionRate_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          CalciumDigestionRate (::std::unique_ptr< CalciumDigestionRate_type > p);

          //@}

          /**
           * @name CarbohydrateAbsorbtionFraction
           *
           * @brief Accessor and modifier functions for the %CarbohydrateAbsorbtionFraction
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarFractionData CarbohydrateAbsorbtionFraction_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< CarbohydrateAbsorbtionFraction_type > CarbohydrateAbsorbtionFraction_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< CarbohydrateAbsorbtionFraction_type, char > CarbohydrateAbsorbtionFraction_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const CarbohydrateAbsorbtionFraction_optional&
          CarbohydrateAbsorbtionFraction () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          CarbohydrateAbsorbtionFraction_optional&
          CarbohydrateAbsorbtionFraction ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          CarbohydrateAbsorbtionFraction (const CarbohydrateAbsorbtionFraction_type& x);

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
          CarbohydrateAbsorbtionFraction (const CarbohydrateAbsorbtionFraction_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          CarbohydrateAbsorbtionFraction (::std::unique_ptr< CarbohydrateAbsorbtionFraction_type > p);

          //@}

          /**
           * @name DefaultCarbohydrateDigestionRate
           *
           * @brief Accessor and modifier functions for the %DefaultCarbohydrateDigestionRate
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarMassPerTimeData DefaultCarbohydrateDigestionRate_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< DefaultCarbohydrateDigestionRate_type > DefaultCarbohydrateDigestionRate_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< DefaultCarbohydrateDigestionRate_type, char > DefaultCarbohydrateDigestionRate_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const DefaultCarbohydrateDigestionRate_optional&
          DefaultCarbohydrateDigestionRate () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          DefaultCarbohydrateDigestionRate_optional&
          DefaultCarbohydrateDigestionRate ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          DefaultCarbohydrateDigestionRate (const DefaultCarbohydrateDigestionRate_type& x);

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
          DefaultCarbohydrateDigestionRate (const DefaultCarbohydrateDigestionRate_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          DefaultCarbohydrateDigestionRate (::std::unique_ptr< DefaultCarbohydrateDigestionRate_type > p);

          //@}

          /**
           * @name DefaultFatDigestionRate
           *
           * @brief Accessor and modifier functions for the %DefaultFatDigestionRate
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarMassPerTimeData DefaultFatDigestionRate_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< DefaultFatDigestionRate_type > DefaultFatDigestionRate_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< DefaultFatDigestionRate_type, char > DefaultFatDigestionRate_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const DefaultFatDigestionRate_optional&
          DefaultFatDigestionRate () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          DefaultFatDigestionRate_optional&
          DefaultFatDigestionRate ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          DefaultFatDigestionRate (const DefaultFatDigestionRate_type& x);

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
          DefaultFatDigestionRate (const DefaultFatDigestionRate_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          DefaultFatDigestionRate (::std::unique_ptr< DefaultFatDigestionRate_type > p);

          //@}

          /**
           * @name DefaultProteinDigestionRate
           *
           * @brief Accessor and modifier functions for the %DefaultProteinDigestionRate
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarMassPerTimeData DefaultProteinDigestionRate_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< DefaultProteinDigestionRate_type > DefaultProteinDigestionRate_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< DefaultProteinDigestionRate_type, char > DefaultProteinDigestionRate_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const DefaultProteinDigestionRate_optional&
          DefaultProteinDigestionRate () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          DefaultProteinDigestionRate_optional&
          DefaultProteinDigestionRate ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          DefaultProteinDigestionRate (const DefaultProteinDigestionRate_type& x);

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
          DefaultProteinDigestionRate (const DefaultProteinDigestionRate_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          DefaultProteinDigestionRate (::std::unique_ptr< DefaultProteinDigestionRate_type > p);

          //@}

          /**
           * @name DefaultStomachContents
           *
           * @brief Accessor and modifier functions for the %DefaultStomachContents
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::NutritionData DefaultStomachContents_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< DefaultStomachContents_type > DefaultStomachContents_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< DefaultStomachContents_type, char > DefaultStomachContents_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const DefaultStomachContents_optional&
          DefaultStomachContents () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          DefaultStomachContents_optional&
          DefaultStomachContents ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          DefaultStomachContents (const DefaultStomachContents_type& x);

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
          DefaultStomachContents (const DefaultStomachContents_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          DefaultStomachContents (::std::unique_ptr< DefaultStomachContents_type > p);

          //@}

          /**
           * @name FatAbsorbtionFraction
           *
           * @brief Accessor and modifier functions for the %FatAbsorbtionFraction
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarFractionData FatAbsorbtionFraction_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< FatAbsorbtionFraction_type > FatAbsorbtionFraction_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< FatAbsorbtionFraction_type, char > FatAbsorbtionFraction_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const FatAbsorbtionFraction_optional&
          FatAbsorbtionFraction () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          FatAbsorbtionFraction_optional&
          FatAbsorbtionFraction ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          FatAbsorbtionFraction (const FatAbsorbtionFraction_type& x);

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
          FatAbsorbtionFraction (const FatAbsorbtionFraction_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          FatAbsorbtionFraction (::std::unique_ptr< FatAbsorbtionFraction_type > p);

          //@}

          /**
           * @name ProteinToUreaFraction
           *
           * @brief Accessor and modifier functions for the %ProteinToUreaFraction
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarFractionData ProteinToUreaFraction_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< ProteinToUreaFraction_type > ProteinToUreaFraction_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< ProteinToUreaFraction_type, char > ProteinToUreaFraction_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const ProteinToUreaFraction_optional&
          ProteinToUreaFraction () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          ProteinToUreaFraction_optional&
          ProteinToUreaFraction ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          ProteinToUreaFraction (const ProteinToUreaFraction_type& x);

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
          ProteinToUreaFraction (const ProteinToUreaFraction_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          ProteinToUreaFraction (::std::unique_ptr< ProteinToUreaFraction_type > p);

          //@}

          /**
           * @name WaterDigestionRate
           *
           * @brief Accessor and modifier functions for the %WaterDigestionRate
           * optional element.
           */
          //@{

          /**
           * @brief Element type.
           */
          typedef ::mil::tatrc::physiology::datamodel::ScalarVolumePerTimeData WaterDigestionRate_type;

          /**
           * @brief Element optional container type.
           */
          typedef ::xsd::cxx::tree::optional< WaterDigestionRate_type > WaterDigestionRate_optional;

          /**
           * @brief Element traits type.
           */
          typedef ::xsd::cxx::tree::traits< WaterDigestionRate_type, char > WaterDigestionRate_traits;

          /**
           * @brief Return a read-only (constant) reference to the element
           * container.
           *
           * @return A constant reference to the optional container.
           */
          const WaterDigestionRate_optional&
          WaterDigestionRate () const;

          /**
           * @brief Return a read-write reference to the element container.
           *
           * @return A reference to the optional container.
           */
          WaterDigestionRate_optional&
          WaterDigestionRate ();

          /**
           * @brief Set the element value.
           *
           * @param x A new value to set.
           *
           * This function makes a copy of its argument and sets it as
           * the new value of the element.
           */
          void
          WaterDigestionRate (const WaterDigestionRate_type& x);

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
          WaterDigestionRate (const WaterDigestionRate_optional& x);

          /**
           * @brief Set the element value without copying.
           *
           * @param p A new value to use.
           *
           * This function will try to use the passed value directly instead
           * of making a copy.
           */
          void
          WaterDigestionRate (::std::unique_ptr< WaterDigestionRate_type > p);

          //@}

          /**
           * @name Constructors
           */
          //@{

          /**
           * @brief Create an instance from the ultimate base and
           * initializers for required elements and attributes.
           */
          GastrointestinalConfiguration ();

          /**
           * @brief Create an instance from a DOM element.
           *
           * @param e A DOM element to extract the data from.
           * @param f Flags to create the new instance with.
           * @param c A pointer to the object that will contain the new
           * instance.
           */
          GastrointestinalConfiguration (const ::xercesc::DOMElement& e,
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
          GastrointestinalConfiguration (const GastrointestinalConfiguration& x,
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
          virtual GastrointestinalConfiguration*
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
          GastrointestinalConfiguration&
          operator= (const GastrointestinalConfiguration& x);

          //@}

          /**
           * @brief Destructor.
           */
          virtual 
          ~GastrointestinalConfiguration ();

          // Implementation.
          //

          //@cond

          protected:
          void
          parse (::xsd::cxx::xml::dom::parser< char >&,
                 ::xml_schema::flags);

          protected:
          CalciumAbsorbtionFraction_optional CalciumAbsorbtionFraction_;
          CalciumDigestionRate_optional CalciumDigestionRate_;
          CarbohydrateAbsorbtionFraction_optional CarbohydrateAbsorbtionFraction_;
          DefaultCarbohydrateDigestionRate_optional DefaultCarbohydrateDigestionRate_;
          DefaultFatDigestionRate_optional DefaultFatDigestionRate_;
          DefaultProteinDigestionRate_optional DefaultProteinDigestionRate_;
          DefaultStomachContents_optional DefaultStomachContents_;
          FatAbsorbtionFraction_optional FatAbsorbtionFraction_;
          ProteinToUreaFraction_optional ProteinToUreaFraction_;
          WaterDigestionRate_optional WaterDigestionRate_;

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
        operator<< (::std::ostream&, const GastrointestinalConfiguration&);
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
        operator<< (::xercesc::DOMElement&, const GastrointestinalConfiguration&);
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

#endif // GASTROINTESTINAL_CONFIGURATION_HXX