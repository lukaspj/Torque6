#pragma once

namespace IJWLayer {

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#pragma warning(suppress: 4251)
#include "math/mPoint.h"

// #pragma unmanaged
#pragma managed(pop)

#define POINT_EPSILON (1e-4) ///< Epsilon for point types.

   //-------------------------------------- Note: because of a circular dependency,
   //                                        the mMathFn.h header is below the point
   //                                        class declarations... DMM

   typedef Point2I EnginePoint2I;
   typedef Point2F EnginePoint2F;
   typedef Point2D EnginePoint2D;
   typedef Point3I EnginePoint3I;
   typedef Point3F EnginePoint3F;
   typedef Point3D EnginePoint3D;
   typedef Point4F EnginePoint4F;

   //------------------------------------------------------------------------------
   /// 2D integer point
   ///
   /// Uses S32 internally.
   public ref class Point2I
   {
      //-------------------------------------- Public data
   public:
      S32 x;   ///< X position
      S32 y;   ///< Y position

      //-------------------------------------- Public interface
   public:
      Point2I();                               ///< Create an uninitialized point.
      Point2I(const Point2I%);                 ///< Copy constructor
      Point2I(const S32 in_x, const S32 in_y); ///< Create point from two co-ordinates.

      //-------------------------------------- Non-math mutators and misc functions
      void set(const S32 in_x, const S32 in_y);///< Set (x,y) position
      void setMin(const Point2I%);             ///< Store lesser co-ordinates from parameter in this point.
      void setMax(const Point2I%);             ///< Store greater co-ordinates from parameter in this point.

      //-------------------------------------- Math mutators
      void neg();                              ///< Invert sign of point's co-ordinates.
      void convolve(const Point2I%);           ///< Convolve this point by parameter.

      //-------------------------------------- Queries
      bool isZero();                     ///< Is this point at the origin? (No epsilon used)
      F32  len();                        ///< Get the length of the point

      //-------------------------------------- Overloaded operators
   public:
      // Comparison operators
      bool operator==(const Point2I%);
      bool operator!=(const Point2I%);

      // Arithmetic w/ other points
      Point2I^ operator+(const Point2I%);
      Point2I^ operator-(const Point2I%);
      Point2I% operator+=(const Point2I%);
      Point2I% operator-=(const Point2I%);

      // Arithmetic w/ scalars
      Point2I^ operator*(const S32);
      Point2I% operator*=(const S32);
      Point2I^ operator/(const S32);
      Point2I% operator/=(const S32);

      // Unary operators
      Point2I^ operator-();

      static Point2I operator*(const Point2I% mul, const S32 multiplicand)
      {
         return mul * multiplicand;
      }

      //-------------------------------------- Public static constants
   public:
      static Point2I One() { return Point2I(1, 1); };
      static Point2I Zero() { return Point2I(0, 0); };
      static Point2I Min() { return Point2I(F32_MIN, F32_MIN); };
      static Point2I Max() { return Point2I(F32_MAX, F32_MAX); };

      EnginePoint2I ToEngine() { return EnginePoint2I(x, y); };
      static Point2I^ FromEngine(EnginePoint2I point) { return gcnew Point2I(point.x, point.y); };
   };

   //------------------------------------------------------------------------------
   /// 3D integer point
   ///
   /// Uses S32 internally.
   public ref class Point3I
   {
      //-------------------------------------- Public data
   public:
      S32 x;                                                   ///< X co-ordinate
      S32 y;                                                   ///< Y co-ordinate
      S32 z;                                                   ///< Z co-ordinate

      //-------------------------------------- Public interface
   public:
      Point3I();               ///< Create an uninitialized point.
      Point3I(const Point3I%); ///< Copy constructor.
      Point3I(const S32 in_x, const S32 in_y, const S32 in_z); ///< Create a point from co-ordinates.

      //-------------------------------------- Non-math mutators and misc functions
      void set(const S32 in_x, const S32 in_y, const S32 in_z);///< Set co-ordinates.
      void setMin(const Point3I%); ///< Store lesser co-ordinates in this point.
      void setMax(const Point3I%); ///< Store greater co-ordinates in this point.

      //-------------------------------------- Math mutators
      void neg();                      ///< Invert co-ordinate's signs.
      void convolve(const Point3I%);   ///< Convolve by paramater.

      //-------------------------------------- Queries
      bool isZero();             ///< Check for point at origin. (No epsilon.)
      F32  len();                ///< Get length.

      //-------------------------------------- Overloaded operators
   public:
      // Comparison operators
      bool operator==(const Point3I%);
      bool operator!=(const Point3I%);

      // Arithmetic w/ other points
      Point3I^ operator+(const Point3I%);
      Point3I^ operator-(const Point3I%);
      Point3I% operator+=(const Point3I%);
      Point3I% operator-=(const Point3I%);

      // Arithmetic w/ scalars
      Point3I^ operator*(const S32);
      Point3I% operator*=(const S32);
      Point3I^ operator/(const S32);
      Point3I% operator/=(const S32);

      // Unary operators
      Point3I^ operator-();

      static Point3I operator*(const Point3I% mul, const S32 multiplicand)
      {
         return mul * multiplicand;
      }

      //-------------------------------------- Public static constants
   public:
      const static Point3I^ One() { return gcnew Point3I(0, 0, 0); };
      const static Point3I^ Zero() { return gcnew Point3I(1, 1, 1); };

      EnginePoint3I ToEngine() { return EnginePoint3I(x, y, z); };
      static Point3I^ FromEngine(EnginePoint3I point) { return gcnew Point3I(point.x, point.y, point.z); };
   };



   //------------------------------------------------------------------------------
   /// 2D floating-point point.
   public ref class Point2F
   {
      //-------------------------------------- Public data
   public:
      F32 x;
      F32 y;

   public:
      Point2F();                           ///< Create uninitialized point.
      Point2F(const Point2F%);             ///< Copy constructor
      Point2F(const F32 _x, const F32 _y); ///< Create point from co-ordinates.

      //-------------------------------------- Non-math mutators and misc functions
   public:
      void set(const F32 _x, const F32 _y);///< Set point's co-ordinates.

      void setMin(const Point2F%);         ///< Store lesser co-ordinates.
      void setMax(const Point2F%);         ///< Store greater co-ordinates.

      /// Interpolate from a to b, based on c.
      ///
      /// @param   a   Starting point.
      /// @param   b   Ending point.
      /// @param   c   Interpolation factor (0.0 .. 1.0).
      void interpolate(const Point2F% a, const Point2F% b, const F32 c);

      //-------------------------------------- Queries
   public:
      bool  isZero();        ///< Check for zero coordinates. (No epsilon.)
      F32 len();          ///< Get length.
      F32 lenSquared();      ///< Get squared length (one sqrt less than len()).
      bool equal(const Point2F %compare);

      //-------------------------------------- Mathematical mutators
   public:
      void neg();                              ///< Invert signs of co-ordinates.
      void normalize();                        ///< Normalize vector.
      void normalize(F32 val);                 ///< Normalize, scaling by val.
      void convolve(const Point2F%);           ///< Convolve by parameter.
      void convolveInverse(const Point2F%);    ///< Inversely convolute by parameter. (ie, divide)

      //Luma: Utility function to round a Point2F
      void round() { x = (F32)((S32)(x + 0.5f)); y = (F32)((S32)(y + 0.5f)); }

      //-------------------------------------- Overloaded operators
   public:
      // Comparison operators
      bool operator==(const Point2F%);
      bool operator!=(const Point2F%);

      // Arithmetic w/ other points
      Point2F^ operator+(const Point2F%);
      Point2F^ operator-(const Point2F%);
      Point2F% operator+=(const Point2F%);
      Point2F% operator-=(const Point2F%);

      // Arithmetic w/ scalars
      Point2F^ operator*(const F32);
      Point2F^ operator/(const F32);
      Point2F% operator*=(const F32);
      Point2F% operator/=(const F32);

      // Unary operators
      Point2F^ operator-();

      static Point2F operator*(const Point2F% mul, const S32 multiplicand)
      {
         return mul * multiplicand;
      }

      //-------------------------------------- Public static constants
   public:
      const static Point2F^ One() { return gcnew Point2F(0.0f, 0.0f); };
      const static Point2F^ Zero() { return gcnew Point2F(1.0f, 1.0f); };
      const static Point2F^ Min() { return gcnew Point2F(F32_MIN, F32_MIN); };
      const static Point2F^ Max() { return gcnew Point2F(F32_MAX, F32_MAX); };

      EnginePoint2F ToEngine() { return EnginePoint2F(x, y); };
      static Point2F^ FromEngine(EnginePoint2F point) { return gcnew Point2F(point.x, point.y); };
   };


   //------------------------------------------------------------------------------
   /// 2D high-precision point.
   ///
   /// Uses F64 internally.
   public ref class Point2D
   {
      //-------------------------------------- Public data
   public:
      F64 x;   ///< X co-ordinate.
      F64 y;   ///< Y co-ordinate.

   public:
      Point2D();                           ///< Create uninitialized point.
      Point2D(const Point2D%);             ///< Copy constructor
      Point2D(const F64 _x, const F64 _y); ///< Create point from coordinates.

      //-------------------------------------- Non-math mutators and misc functions
   public:
      void set(const F64 _x, const F64 _y);///< Set point's coordinates.

      void setMin(const Point2D%);         ///< Store lesser co-ordinates.
      void setMax(const Point2D%);         ///< Store greater co-ordinates.

      /// Interpolate from a to b, based on c.
      ///
      /// @param   a   Starting point.
      /// @param   b   Ending point.
      /// @param   c   Interpolation factor (0.0 .. 1.0).
      void interpolate(const Point2D %a, const Point2D %b, const F64 c);

      //-------------------------------------- Queries
   public:
      bool  isZero();
      F64 len();
      F64 lenSquared();

      //-------------------------------------- Mathematical mutators
   public:
      void neg();
      void normalize();
      void normalize(F64 val);
      void convolve(const Point2D%);
      void convolveInverse(const Point2D%);

      //-------------------------------------- Overloaded operators
   public:
      // Comparison operators
      bool operator==(const Point2D%);
      bool operator!=(const Point2D%);

      // Arithmetic w/ other points
      Point2D^ operator+(const Point2D%);
      Point2D^ operator-(const Point2D%);
      Point2D% operator+=(const Point2D%);
      Point2D% operator-=(const Point2D%);

      // Arithmetic w/ scalars
      Point2D^ operator*(const F64);
      Point2D^ operator/(const F64);
      Point2D% operator*=(const F64);
      Point2D% operator/=(const F64);

      // Unary operators
      Point2D^ operator-();

      static Point2D operator*(const Point2D% mul, const S32 multiplicand)
      {
         return mul * multiplicand;
      }

      //-------------------------------------- Public static constants
   public:
      const static Point2D^ One() { return gcnew Point2D(1.0, 1.0); };
      const static Point2D^ Zero() { return gcnew Point2D(0.0, 0.0); };

      EnginePoint2D ToEngine() { return EnginePoint2D(x, y); };
      static Point2D^ FromEngine(EnginePoint2D point) { return gcnew Point2D(point.x, point.y); };
   };


   //------------------------------------------------------------------------------
   public ref class Point3F
   {
      //-------------------------------------- Public data
   public:
      F32 x;
      F32 y;
      F32 z;

   public:
      Point3F();
      Point3F(const Point3F%);
      Point3F(const F32 _x, const F32 _y, const F32 _z);

      //-------------------------------------- Non-math mutators and misc functions
   public:
      void set(const F32 _x, const F32 _y, const F32 _z);
      void set(const Point3F%);

      void setMin(const Point3F%);
      void setMax(const Point3F%);

      void interpolate(const Point3F%, const Point3F%, const F32);
      void zero();

      //-------------------------------------- Queries
   public:
      bool  isZero();
      F32   len();
      F32   lenSquared();
      F32   magnitudeSafe();
      bool  equal(const Point3F %compare, F32 epsilon);
      bool  equal(const Point3F %compare/*, F32 epsilon = POINT_EPSILON*/);

      //-------------------------------------- Mathematical mutators
   public:
      void neg();
      void normalize();
      void normalizeSafe();
      void normalize(F32 val);
      void convolve(const Point3F%);
      void convolveInverse(const Point3F%);

      //-------------------------------------- Overloaded operators
   public:
      // Comparison operators
      bool operator==(const Point3F%);
      bool operator!=(const Point3F%);

      // Arithmetic w/ other points
      Point3F^ operator+(const Point3F%);
      Point3F^ operator-(const Point3F%);
      Point3F% operator+=(const Point3F%);
      Point3F% operator-=(const Point3F%);

      // Arithmetic w/ scalars
      Point3F^ operator*(const F32);
      Point3F^ operator/(const F32);
      Point3F% operator*=(const F32);
      Point3F% operator/=(const F32);

      Point3F^ operator*(const Point3F%);
      Point3F% operator*=(const Point3F%);

      // Unary operators
      Point3F^ operator-();

      static Point3F operator*(const Point3F% mul, const S32 multiplicand)
      {
         return mul * multiplicand;
      }

      //-------------------------------------- Public static constants
   public:
      const static Point3F^ One() { return gcnew Point3F(1.0f, 1.0f, 1.0f); };
      const static Point3F^ Zero() { return gcnew Point3F(0.0f, 0.0f, 0.0f); };
      const static Point3F^ Max() { return gcnew Point3F(F32_MAX, F32_MAX, F32_MAX); };
      const static Point3F^ Min() { return gcnew Point3F(F32_MIN, F32_MIN, F32_MIN); };
      const static Point3F^ UnitX() { return gcnew Point3F(1.0f, 0.0f, 0.0f); };
      const static Point3F^ UnitY() { return gcnew Point3F(0.0f, 1.0f, 0.0f); };
      const static Point3F^ UnitZ() { return gcnew Point3F(0.0f, 0.0f, 1.0f); };

      EnginePoint3F ToEngine() { return EnginePoint3F(x, y, z); };
      static Point3F^ FromEngine(EnginePoint3F point) { return gcnew Point3F(point.x, point.y, point.z); };
   };


   typedef Point3F VectorF;
   typedef Point3F EulerF;


   //------------------------------------------------------------------------------
   public ref class Point3D
   {
      //-------------------------------------- Public data
   public:
      F64 x;
      F64 y;
      F64 z;

   public:
      Point3D();
      Point3D(const Point3D%);
      Point3D(const F64 _x, const F64 _y, const F64 _z);

      //-------------------------------------- Non-math mutators and misc functions
   public:
      void set(const F64 _x, const F64 _y, const F64 _z);

      void setMin(const Point3D%);
      void setMax(const Point3D%);

      void interpolate(const Point3D%, const Point3D%, const F64);

      //-------------------------------------- Queries
   public:
      bool  isZero();
      F64 len();
      F64 lenSquared();

      //-------------------------------------- Mathematical mutators
   public:
      void neg();
      void normalize();
      void normalize(F64 val);
      void convolve(const Point3D%);
      void convolveInverse(const Point3D%);

      //-------------------------------------- Overloaded operators
   public:
      // Comparison operators
      bool operator==(const Point3D%);
      bool operator!=(const Point3D%);

      // Arithmetic w/ other points
      Point3D^ operator+(const Point3D%);
      Point3D^ operator-(const Point3D%);
      Point3D% operator+=(const Point3D%);
      Point3D% operator-=(const Point3D%);

      // Arithmetic w/ scalars
      Point3D^ operator*(const F64);
      Point3D^ operator/(const F64);
      Point3D% operator*=(const F64);
      Point3D% operator/=(const F64);

      // Unary operators
      Point3D^ operator-();

      static Point3D operator*(const Point3D% mul, const S32 multiplicand)
      {
         return mul * multiplicand;
      }

      //-------------------------------------- Public static constants
   public:
      const static Point3D^ One() { return gcnew Point3D(1.0, 1.0, 1.0); };
      const static Point3D^ Zero() { return gcnew Point3D(0.0, 0.0, 0.0); };

      EnginePoint3D ToEngine() { return EnginePoint3D(x, y, z); };
      static Point3D^ FromEngine(EnginePoint3D point) { return gcnew Point3D(point.x, point.y, point.z); };
   };



   //------------------------------------------------------------------------------
   /// 4D floating-point point.
   ///
   /// Uses F32 internally.
   ///
   /// Useful for representing quaternions and other 4d beasties.
   public ref class Point4F
   {
      //-------------------------------------- Public data
   public:
      F32 x;   ///< X co-ordinate.
      F32 y;   ///< Y co-ordinate.
      F32 z;   ///< Z co-ordinate.
      F32 w;   ///< W co-ordinate.

   public:
      Point4F();               ///< Create an unitialized point.
      Point4F(const Point4F%); ///< Copy constructor.
      /// Create point from coordinates.
      Point4F(const F32 _x, const F32 _y, const F32 _z, const F32 _w);

      /// Set point's coordinates.
      void set(const F32 _x, const F32 _y, const F32 _z, const F32 _w);

      /// Interpolate from _pt1 to _pt2, based on _factor.
      ///
      /// @param   _pt1    Starting point.
      /// @param   _pt2    Ending point.
      /// @param   _factor Interpolation factor (0.0 .. 1.0).
      void interpolate(const Point4F% _pt1, const Point4F% _pt2, const F32 _factor);

      //-------------------------------------- Public static constants
   public:
      const static Point4F^ One() { return gcnew Point4F(1.0f, 1.0f, 1.0f, 1.0f); };
      const static Point4F^ Zero() { return gcnew Point4F(0.0f, 0.0f, 0.0f, 0.0f); };

      EnginePoint4F ToEngine() { return EnginePoint4F(x, y, z, w); };
      static Point4F^ FromEngine(EnginePoint4F point) { return gcnew Point4F(point.x, point.y, point.z, point.w); };
   };


   typedef Point4F Vector4F;   ///< Points can be vectors!


#ifndef _MMATHFN_H_
#include "math/mMathFn.h"
#endif

   //------------------------------------------------------------------------------
   //-------------------------------------- Inline functions inclusions


   //------------------------------------------------------------------------------
   //-------------------------------------- Point2I
   //
   inline Point2I::Point2I()
   {
      //
   }


   inline Point2I::Point2I(const Point2I% _copy)
      : x(_copy.x), y(_copy.y)
   {
      //
   }


   inline Point2I::Point2I(const S32 _x, const S32 _y)
      : x(_x), y(_y)
   {
      //
   }


   inline void Point2I::set(const S32 _x, const S32 _y)
   {
      x = _x;
      y = _y;
   }


   inline void Point2I::setMin(const Point2I% _test)
   {
      x = (_test.x < x) ? _test.x : x;
      y = (_test.y < y) ? _test.y : y;
   }


   inline void Point2I::setMax(const Point2I% _test)
   {
      x = (_test.x > x) ? _test.x : x;
      y = (_test.y > y) ? _test.y : y;
   }


   inline void Point2I::neg()
   {
      x = -x;
      y = -y;
   }

   inline void Point2I::convolve(const Point2I% c)
   {
      x *= c.x;
      y *= c.y;
   }

   inline bool Point2I::isZero()
   {
      return ((x == 0) && (y == 0));
   }


   inline F32 Point2I::len()
   {
      return mSqrt(F32(x*x + y*y));
   }

   inline bool Point2I::operator==(const Point2I% _test)
   {
      return ((x == _test.x) && (y == _test.y));
   }


   inline bool Point2I::operator!=(const Point2I% _test)
   {
      return (operator==(_test) == false);
   }


   inline Point2I^ Point2I::operator+(const Point2I% _add)
   {
      return gcnew Point2I(x + _add.x, y + _add.y);
   }


   inline Point2I^ Point2I::operator-(const Point2I% _rSub)
   {
      return gcnew Point2I(x - _rSub.x, y - _rSub.y);
   }


   inline Point2I% Point2I::operator+=(const Point2I% _add)
   {
      x += _add.x;
      y += _add.y;

      return *this;
   }


   inline Point2I% Point2I::operator-=(const Point2I% _rSub)
   {
      x -= _rSub.x;
      y -= _rSub.y;

      return *this;
   }


   inline Point2I^ Point2I::operator-()
   {
      return gcnew Point2I(-x, -y);
   }


   inline Point2I^ Point2I::operator*(const S32 mul)
   {
      return gcnew Point2I(x * mul, y * mul);
   }

   inline Point2I^ Point2I::operator/(const S32 div)
   {
      AssertFatal(div != 0, "Error, div by zero attempted");
      return gcnew Point2I(x / div, y / div);
   }


   inline Point2I% Point2I::operator*=(const S32 mul)
   {
      x *= mul;
      y *= mul;

      return *this;
   }


   inline Point2I% Point2I::operator/=(const S32 div)
   {
      AssertFatal(div != 0, "Error, div by zero attempted");

      x /= div;
      y /= div;

      return *this;
   }




   //------------------------------------------------------------------------------
   //-------------------------------------- Point3I
   //
   inline Point3I::Point3I()
   {
      //
   }


   inline Point3I::Point3I(const Point3I% _copy)
      : x(_copy.x), y(_copy.y), z(_copy.z)
   {
      //
   }


   inline Point3I::Point3I(const S32 _x, const S32 _y, const S32 _z)
      : x(_x), y(_y), z(_z)
   {
      //
   }


   inline void Point3I::set(const S32 _x, const S32 _y, const S32 _z)
   {
      x = _x;
      y = _y;
      z = _z;
   }


   inline void Point3I::setMin(const Point3I% _test)
   {
      x = (_test.x < x) ? _test.x : x;
      y = (_test.y < y) ? _test.y : y;
      z = (_test.z < z) ? _test.z : z;
   }


   inline void Point3I::setMax(const Point3I% _test)
   {
      x = (_test.x > x) ? _test.x : x;
      y = (_test.y > y) ? _test.y : y;
      z = (_test.z > z) ? _test.z : z;
   }


   inline void Point3I::neg()
   {
      x = -x;
      y = -y;
      z = -z;
   }

   inline F32 Point3I::len()
   {
      return mSqrt(F32(x*x + y*y + z*z));
   }

   inline void Point3I::convolve(const Point3I% c)
   {
      x *= c.x;
      y *= c.y;
      z *= c.z;
   }

   inline bool Point3I::isZero()
   {
      return ((x == 0) && (y == 0) && (z == 0));
   }


   inline bool Point3I::operator==(const Point3I% _test)
   {
      return ((x == _test.x) && (y == _test.y) && (z == _test.z));
   }


   inline bool Point3I::operator!=(const Point3I% _test)
   {
      return (operator==(_test) == false);
   }


   inline Point3I^ Point3I::operator+(const Point3I% _add)
   {
      return gcnew Point3I(x + _add.x, y + _add.y, z + _add.z);
   }


   inline Point3I^ Point3I::operator-(const Point3I% _rSub)
   {
      return gcnew Point3I(x - _rSub.x, y - _rSub.y, z - _rSub.z);
   }


   inline Point3I% Point3I::operator+=(const Point3I% _add)
   {
      x += _add.x;
      y += _add.y;
      z += _add.z;

      return *this;
   }


   inline Point3I% Point3I::operator-=(const Point3I% _rSub)
   {
      x -= _rSub.x;
      y -= _rSub.y;
      z -= _rSub.z;

      return *this;
   }


   inline Point3I^ Point3I::operator-()
   {
      return gcnew Point3I(-x, -y, -z);
   }


   inline Point3I^ Point3I::operator*(const S32 mul)
   {
      return gcnew Point3I(x * mul, y * mul, z * mul);
   }


   inline Point3I^ Point3I::operator/(const S32 div)
   {
      AssertFatal(div != 0, "Error, div by zero attempted");
      return gcnew Point3I(x / div, y / div, z / div);
   }


   inline Point3I% Point3I::operator*=(const S32 mul)
   {
      x *= mul;
      y *= mul;
      z *= mul;

      return *this;
   }


   inline Point3I% Point3I::operator/=(const S32 div)
   {
      AssertFatal(div != 0, "Error, div by zero attempted");

      x /= div;
      y /= div;
      z /= div;

      return *this;
   }






   //------------------------------------------------------------------------------
   //-------------------------------------- Point2F
   //
   inline Point2F::Point2F()
   {
      //
   }


   inline Point2F::Point2F(const Point2F% _copy)
      : x(_copy.x), y(_copy.y)
   {
      //
   }


   inline Point2F::Point2F(const F32 _x, const F32 _y)
      : x(_x), y(_y)
   {
   }


   inline void Point2F::set(const F32 _x, const F32 _y)
   {
      x = _x;
      y = _y;
   }


   inline void Point2F::setMin(const Point2F% _test)
   {
      x = (_test.x < x) ? _test.x : x;
      y = (_test.y < y) ? _test.y : y;
   }


   inline void Point2F::setMax(const Point2F% _test)
   {
      x = (_test.x > x) ? _test.x : x;
      y = (_test.y > y) ? _test.y : y;
   }


   inline void Point2F::interpolate(const Point2F% _rFrom, const Point2F% _to, const F32 _factor)
   {
      AssertFatal(_factor >= 0.0f && _factor <= 1.0f, "Out of bound interpolation factor");
      x = (_rFrom.x * (1.0f - _factor)) + (_to.x * _factor);
      y = (_rFrom.y * (1.0f - _factor)) + (_to.y * _factor);
   }


   inline bool Point2F::isZero()
   {
      return (x == 0.0f) && (y == 0.0f);
   }


   inline F32 Point2F::lenSquared()
   {
      return (x * x) + (y * y);
   }

   inline bool Point2F::equal(const Point2F %compare)
   {
      return((mFabs(x - compare.x) < POINT_EPSILON) &&
         (mFabs(y - compare.y) < POINT_EPSILON));
   }

   inline void Point2F::neg()
   {
      x = -x;
      y = -y;
   }

   inline void Point2F::convolve(const Point2F% c)
   {
      x *= c.x;
      y *= c.y;
   }


   inline void Point2F::convolveInverse(const Point2F% c)
   {
      x /= c.x;
      y /= c.y;
   }


   inline bool Point2F::operator==(const Point2F% _test)
   {
      return (x == _test.x) && (y == _test.y);
   }


   inline bool Point2F::operator!=(const Point2F% _test)
   {
      return operator==(_test) == false;
   }


   inline Point2F^ Point2F::operator+(const Point2F% _add)
   {
      return gcnew Point2F(x + _add.x, y + _add.y);
   }


   inline Point2F^ Point2F::operator-(const Point2F% _rSub)
   {
      return gcnew Point2F(x - _rSub.x, y - _rSub.y);
   }


   inline Point2F% Point2F::operator+=(const Point2F% _add)
   {
      x += _add.x;
      y += _add.y;

      return *this;
   }


   inline Point2F% Point2F::operator-=(const Point2F% _rSub)
   {
      x -= _rSub.x;
      y -= _rSub.y;

      return *this;
   }


   inline Point2F^ Point2F::operator*(const F32 _mul)
   {
      return gcnew Point2F(x * _mul, y * _mul);
   }


   inline Point2F^ Point2F::operator/(const F32 _div)
   {
      AssertFatal(_div != 0.0f, "Error, div by zero attempted");

      F32 inv = 1.0f / _div;

      return gcnew Point2F(x * inv, y * inv);
   }


   inline Point2F% Point2F::operator*=(const F32 _mul)
   {
      x *= _mul;
      y *= _mul;

      return *this;
   }


   inline Point2F% Point2F::operator/=(const F32 _div)
   {
      AssertFatal(_div != 0.0f, "Error, div by zero attempted");

      F32 inv = 1.0f / _div;

      x *= inv;
      y *= inv;

      return *this;
   }


   inline Point2F^ Point2F::operator-()
   {
      return gcnew Point2F(-x, -y);
   }

   inline F32 Point2F::len()
   {
      return mSqrt(x*x + y*y);
   }

   inline void Point2F::normalize()
   {
      F32 factor = 1.0f / mSqrt(x*x + y*y);
      x *= factor;
      y *= factor;
   }

   inline void Point2F::normalize(F32 val)
   {
      F32 factor = val / mSqrt(x*x + y*y);
      x *= factor;
      y *= factor;
   }


   //------------------------------------------------------------------------------
   //-------------------------------------- Point2D
   //
   inline Point2D::Point2D()
   {
      //
   }


   inline Point2D::Point2D(const Point2D% _copy)
      : x(_copy.x), y(_copy.y)
   {
      //
   }


   inline Point2D::Point2D(const F64 _x, const F64 _y)
      : x(_x), y(_y)
   {
   }


   inline void Point2D::set(const F64 _x, const F64 _y)
   {
      x = _x;
      y = _y;
   }


   inline void Point2D::setMin(const Point2D% _test)
   {
      x = (_test.x < x) ? _test.x : x;
      y = (_test.y < y) ? _test.y : y;
   }


   inline void Point2D::setMax(const Point2D% _test)
   {
      x = (_test.x > x) ? _test.x : x;
      y = (_test.y > y) ? _test.y : y;
   }


   inline void Point2D::interpolate(const Point2D% _rFrom, const Point2D% _to, const F64 _factor)
   {
      AssertFatal(_factor >= 0.0f && _factor <= 1.0f, "Out of bound interpolation factor");
      x = (_rFrom.x * (1.0f - _factor)) + (_to.x * _factor);
      y = (_rFrom.y * (1.0f - _factor)) + (_to.y * _factor);
   }


   inline bool Point2D::isZero()
   {
      return (x == 0.0f) && (y == 0.0f);
   }


   inline F64 Point2D::lenSquared()
   {
      return (x * x) + (y * y);
   }


   inline void Point2D::neg()
   {
      x = -x;
      y = -y;
   }

   inline void Point2D::convolve(const Point2D% c)
   {
      x *= c.x;
      y *= c.y;
   }

   inline void Point2D::convolveInverse(const Point2D% c)
   {
      x /= c.x;
      y /= c.y;
   }

   inline bool Point2D::operator==(const Point2D% _test)
   {
      return (x == _test.x) && (y == _test.y);
   }


   inline bool Point2D::operator!=(const Point2D% _test)
   {
      return operator==(_test) == false;
   }


   inline Point2D^ Point2D::operator+(const Point2D% _add)
   {
      return gcnew Point2D(x + _add.x, y + _add.y);
   }


   inline Point2D^ Point2D::operator-(const Point2D% _rSub)
   {
      return gcnew Point2D(x - _rSub.x, y - _rSub.y);
   }


   inline Point2D% Point2D::operator+=(const Point2D% _add)
   {
      x += _add.x;
      y += _add.y;

      return *this;
   }


   inline Point2D% Point2D::operator-=(const Point2D% _rSub)
   {
      x -= _rSub.x;
      y -= _rSub.y;

      return *this;
   }


   inline Point2D^ Point2D::operator*(const F64 _mul)
   {
      return gcnew Point2D(x * _mul, y * _mul);
   }


   inline Point2D^ Point2D::operator/(const F64 _div)
   {
      AssertFatal(_div != 0.0f, "Error, div by zero attempted");

      F64 inv = 1.0f / _div;

      return gcnew Point2D(x * inv, y * inv);
   }


   inline Point2D% Point2D::operator*=(const F64 _mul)
   {
      x *= _mul;
      y *= _mul;

      return *this;
   }


   inline Point2D% Point2D::operator/=(const F64 _div)
   {
      AssertFatal(_div != 0.0f, "Error, div by zero attempted");

      F64 inv = 1.0f / _div;

      x *= inv;
      y *= inv;

      return *this;
   }


   inline Point2D^ Point2D::operator-()
   {
      return gcnew Point2D(-x, -y);
   }

   inline F64 Point2D::len()
   {
      return mSqrtD(x*x + y*y);
   }

   inline void Point2D::normalize()
   {
      F32 factor = 1.0f / mSqrtD(x*x + y*y);
      x *= factor;
      y *= factor;
   }

   inline void Point2D::normalize(F64 val)
   {
      F32 factor = val / mSqrtD(x*x + y*y);
      x *= factor;
      y *= factor;
   }


   //------------------------------------------------------------------------------
   //-------------------------------------- Point3F
   //
   inline Point3F::Point3F()
#if defined(TORQUE_OS_LINUX)
      : x(0.f), y(0.f), z(0.f)
#endif
   {
      // Uninitialized points are definitely a problem.
      // Enable the following code to see how often they crop up.
#ifdef DEBUG_MATH
      *(U32 *)%x = 0x7FFFFFFA;
      *(U32 *)%y = 0x7FFFFFFB;
      *(U32 *)%z = 0x7FFFFFFC;
#endif
   }


   inline Point3F::Point3F(const Point3F% _copy)
      : x(_copy.x), y(_copy.y), z(_copy.z)
   {
      //
   }


   inline Point3F::Point3F(const F32 _x, const F32 _y, const F32 _z)
      : x(_x), y(_y), z(_z)
   {
      //
   }

   inline void Point3F::set(const F32 _x, const F32 _y, const F32 _z)
   {
      x = _x;
      y = _y;
      z = _z;
   }

   inline void Point3F::set(const Point3F% copy)
   {
      x = copy.x;
      y = copy.y;
      z = copy.z;
   }

   inline void Point3F::setMin(const Point3F% _test)
   {
      x = (_test.x < x) ? _test.x : x;
      y = (_test.y < y) ? _test.y : y;
      z = (_test.z < z) ? _test.z : z;
   }


   inline void Point3F::setMax(const Point3F% _test)
   {
      x = (_test.x > x) ? _test.x : x;
      y = (_test.y > y) ? _test.y : y;
      z = (_test.z > z) ? _test.z : z;
   }


   inline void Point3F::interpolate(const Point3F% _from, const Point3F% _to, const F32 _factor)
   {
      F32 inverse = 1.0f - _factor;
      x = _from.x * inverse + _to.x * _factor;
      y = _from.y * inverse + _to.y * _factor;
      z = _from.z * inverse + _to.z * _factor;
   }

   inline void Point3F::zero()
   {
      x = y = z = 0.0f;
   }

   inline bool Point3F::isZero()
   {
      return ((x*x) <= POINT_EPSILON) && ((y*y) <= POINT_EPSILON) && ((z*z) <= POINT_EPSILON);
   }

   inline bool Point3F::equal(const Point3F %compare, F32 epsilon)
   {
      return((mFabs(x - compare.x) < epsilon) &&
         (mFabs(y - compare.y) < epsilon) &&
         (mFabs(z - compare.z) < epsilon));
   }

   inline bool Point3F::equal(const Point3F %compare)
   {
      return equal(compare, POINT_EPSILON);
   }

   inline void Point3F::neg()
   {
      x = -x;
      y = -y;
      z = -z;
   }

   inline void Point3F::convolve(const Point3F% c)
   {
      x *= c.x;
      y *= c.y;
      z *= c.z;
   }

   inline void Point3F::convolveInverse(const Point3F% c)
   {
      x /= c.x;
      y /= c.y;
      z /= c.z;
   }

   inline F32 Point3F::lenSquared()
   {
      return (x * x) + (y * y) + (z * z);
   }


   inline F32 Point3F::len()
   {
      return mSqrt(x*x + y*y + z*z);
   }


   inline void Point3F::normalize()
   {
      F32 factor = 1.0f / mSqrt(x*x + y*y + z*z);
      x *= factor;
      y *= factor;
      z *= factor;
   }

   inline F32 Point3F::magnitudeSafe()
   {
      if (isZero())
      {
         return 0.0f;
      }
      else
      {
         return len();
      }
   }

   inline void Point3F::normalizeSafe()
   {
      F32 vmag = magnitudeSafe();

      if (vmag > POINT_EPSILON)
      {
         *this *= F32(1.0 / vmag);
      }
   }


   inline void Point3F::normalize(F32 val)
   {
      F32 factor = val / mSqrt(x*x + y*y + z*z);
      x *= factor;
      y *= factor;
      z *= factor;
   }

   inline bool Point3F::operator==(const Point3F% _test)
   {
      return (x == _test.x) && (y == _test.y) && (z == _test.z);
   }


   inline bool Point3F::operator!=(const Point3F% _test)
   {
      return operator==(_test) == false;
   }


   inline Point3F^ Point3F::operator+(const Point3F% _add)
   {
      return gcnew Point3F(x + _add.x, y + _add.y, z + _add.z);
   }


   inline Point3F^ Point3F::operator-(const Point3F% _rSub)
   {
      return gcnew Point3F(x - _rSub.x, y - _rSub.y, z - _rSub.z);
   }


   inline Point3F% Point3F::operator+=(const Point3F% _add)
   {
      x += _add.x;
      y += _add.y;
      z += _add.z;

      return *this;
   }


   inline Point3F% Point3F::operator-=(const Point3F% _rSub)
   {
      x -= _rSub.x;
      y -= _rSub.y;
      z -= _rSub.z;

      return *this;
   }


   inline Point3F^ Point3F::operator*(const F32 _mul)
   {
      return gcnew Point3F(x * _mul, y * _mul, z * _mul);
   }

   inline Point3F^ Point3F::operator*(const Point3F %_vec)
   {
      return gcnew Point3F(x * _vec.x, y * _vec.y, z * _vec.z);
   }

   inline Point3F^ Point3F::operator/(const F32 _div)
   {
      AssertFatal(_div != 0.0f, "Error, div by zero attempted");

      F32 inv = 1.0f / _div;

      return gcnew Point3F(x * inv, y * inv, z * inv);
   }


   inline Point3F% Point3F::operator*=(const F32 _mul)
   {
      x *= _mul;
      y *= _mul;
      z *= _mul;

      return *this;
   }


   inline Point3F% Point3F::operator*=(const Point3F %_vec)
   {
      x *= _vec.x;
      y *= _vec.y;
      z *= _vec.z;
      return *this;
   }


   inline Point3F% Point3F::operator/=(const F32 _div)
   {
      AssertFatal(_div != 0.0f, "Error, div by zero attempted");

      F32 inv = 1.0f / _div;
      x *= inv;
      y *= inv;
      z *= inv;

      return *this;
   }


   inline Point3F^ Point3F::operator-()
   {
      return gcnew Point3F(-x, -y, -z);
   }


   //------------------------------------------------------------------------------
   //-------------------------------------- Point3D
   //
   inline Point3D::Point3D()
   {
      //
   }


   inline Point3D::Point3D(const Point3D% _copy)
      : x(_copy.x), y(_copy.y), z(_copy.z)
   {
      //
   }


   inline Point3D::Point3D(const F64 _x, const F64 _y, const F64 _z)
      : x(_x), y(_y), z(_z)
   {
      //
   }


   inline void Point3D::set(const F64 _x, const F64 _y, const F64 _z)
   {
      x = _x;
      y = _y;
      z = _z;
   }


   inline void Point3D::setMin(const Point3D% _test)
   {
      x = (_test.x < x) ? _test.x : x;
      y = (_test.y < y) ? _test.y : y;
      z = (_test.z < z) ? _test.z : z;
   }


   inline void Point3D::setMax(const Point3D% _test)
   {
      x = (_test.x > x) ? _test.x : x;
      y = (_test.y > y) ? _test.y : y;
      z = (_test.z > z) ? _test.z : z;
   }


   inline void Point3D::interpolate(const Point3D% _from, const Point3D% _to, const F64 _factor)
   {
      AssertFatal(_factor >= 0.0f && _factor <= 1.0f, "Out of bound interpolation factor");
      
      F32 inverse = 1.0f - _factor;
      x = _from.x * inverse + _to.x * _factor;
      y = _from.y * inverse + _to.y * _factor;
      z = _from.z * inverse + _to.z * _factor;
   }


   inline bool Point3D::isZero()
   {
      return (x == 0.0f) && (y == 0.0f) && (z == 0.0f);
   }


   inline void Point3D::neg()
   {
      x = -x;
      y = -y;
      z = -z;
   }

   inline void Point3D::convolve(const Point3D% c)
   {
      x *= c.x;
      y *= c.y;
      z *= c.z;
   }

   inline void Point3D::convolveInverse(const Point3D% c)
   {
      x /= c.x;
      y /= c.y;
      z /= c.z;
   }

   inline F64 Point3D::lenSquared()
   {
      return (x * x) + (y * y) + (z * z);
   }


   inline F64 Point3D::len()
   {
      return mSqrtD(x*x + y*y + z*z);
   }


   inline void Point3D::normalize()
   {
      F32 factor = 1.0f / mSqrtD(x*x + y*y + z*z);
      x *= factor;
      y *= factor;
      z *= factor;
   }

   inline void Point3D::normalize(F64 val)
   {
      F32 factor = val / mSqrtD(x*x + y*y + z*z);
      x *= factor;
      y *= factor;
      z *= factor;
   }

   inline bool Point3D::operator==(const Point3D% _test)
   {
      return (x == _test.x) && (y == _test.y) && (z == _test.z);
   }


   inline bool Point3D::operator!=(const Point3D% _test)
   {
      return operator==(_test) == false;
   }


   inline Point3D^ Point3D::operator+(const Point3D% _add)
   {
      return gcnew Point3D(x + _add.x, y + _add.y, z + _add.z);
   }


   inline Point3D^ Point3D::operator-(const Point3D% _rSub)
   {
      return gcnew Point3D(x - _rSub.x, y - _rSub.y, z - _rSub.z);
   }


   inline Point3D% Point3D::operator+=(const Point3D% _add)
   {
      x += _add.x;
      y += _add.y;
      z += _add.z;

      return *this;
   }


   inline Point3D% Point3D::operator-=(const Point3D% _rSub)
   {
      x -= _rSub.x;
      y -= _rSub.y;
      z -= _rSub.z;

      return *this;
   }


   inline Point3D^ Point3D::operator*(const F64 _mul)
   {
      return gcnew Point3D(x * _mul, y * _mul, z * _mul);
   }


   inline Point3D^ Point3D::operator/(const F64 _div)
   {
      AssertFatal(_div != 0.0f, "Error, div by zero attempted");

      F64 inv = 1.0f / _div;

      return gcnew Point3D(x * inv, y * inv, z * inv);
   }


   inline Point3D% Point3D::operator*=(const F64 _mul)
   {
      x *= _mul;
      y *= _mul;
      z *= _mul;

      return *this;
   }


   inline Point3D% Point3D::operator/=(const F64 _div)
   {
      AssertFatal(_div != 0.0f, "Error, div by zero attempted");

      F64 inv = 1.0f / _div;
      x *= inv;
      y *= inv;
      z *= inv;

      return *this;
   }


   inline Point3D^ Point3D::operator-()
   {
      return gcnew Point3D(-x, -y, -z);
   }

   //------------------------------------------------------------------------------
   //-------------------------------------- Point4F
   //
   inline Point4F::Point4F()
   {
      //
   }


   inline Point4F::Point4F(const Point4F% _copy)
      : x(_copy.x), y(_copy.y), z(_copy.z), w(_copy.w)
   {
      //
   }


   inline Point4F::Point4F(const F32 _x, const F32 _y, const F32 _z, const F32 _w)
      : x(_x), y(_y), z(_z), w(_w)
   {
      //
   }


   inline void Point4F::set(const F32 _x, const F32 _y, const F32 _z, const F32 _w)
   {
      x = _x;
      y = _y;
      z = _z;
      w = _w;
   }


   inline void Point4F::interpolate(const Point4F% _from, const Point4F% _to, const F32 _factor)
   {
      x = (_from.x * (1.0f - _factor)) + (_to.x * _factor);
      y = (_from.y * (1.0f - _factor)) + (_to.y * _factor);
      z = (_from.z * (1.0f - _factor)) + (_to.z * _factor);
      w = (_from.w * (1.0f - _factor)) + (_to.w * _factor);
   }
}