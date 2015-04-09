#include "../../stdafx.h"
#include "../Headers/GuiWrappers.h"
#include "../Headers/MarshalHelper.h"
#include "../../ConsoleTypes/Headers/Points.h"

using namespace System::Runtime::InteropServices;

typedef FontCharset EngineFontCharset;

bool IJWLayer::GuiControlProfile::Tab::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mTabable;
}

void IJWLayer::GuiControlProfile::Tab::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mTabable = value;
}

bool IJWLayer::GuiControlProfile::CanKeyFocus::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mCanKeyFocus;
}

void IJWLayer::GuiControlProfile::CanKeyFocus::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mCanKeyFocus = value;
}

bool IJWLayer::GuiControlProfile::MouseOverSelected::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mMouseOverSelected;
}

void IJWLayer::GuiControlProfile::MouseOverSelected::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mMouseOverSelected = value;
}

bool IJWLayer::GuiControlProfile::Modal::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mModal;
}

void IJWLayer::GuiControlProfile::Modal::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mModal = value;
}

bool IJWLayer::GuiControlProfile::Opaque::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mOpaque;
}

void IJWLayer::GuiControlProfile::Opaque::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mOpaque = value;
}

Color^ IJWLayer::GuiControlProfile::FillColor::get()
{
   if (!IsAlive())
      return nullptr;
   return Color::FromArgb(GetObjectPtr()->mFillColor.red, 
      GetObjectPtr()->mFillColor.green, 
      GetObjectPtr()->mFillColor.blue, 
      GetObjectPtr()->mFillColor.alpha);
}

void IJWLayer::GuiControlProfile::FillColor::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFillColor = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::FillColorHL::get()
{
   if (!IsAlive())
      return nullptr;
   return Color::FromArgb(GetObjectPtr()->mFillColorHL.red, 
      GetObjectPtr()->mFillColorHL.green,
      GetObjectPtr()->mFillColorHL.blue,
      GetObjectPtr()->mFillColorHL.alpha);
}

void IJWLayer::GuiControlProfile::FillColorHL::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFillColorHL = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::FillColorNA::get()
{
   if (!IsAlive())
      return nullptr;
   return Color::FromArgb(GetObjectPtr()->mFillColorNA.red, 
      GetObjectPtr()->mFillColorNA.green,
      GetObjectPtr()->mFillColorNA.blue,
      GetObjectPtr()->mFillColorNA.alpha);
}

void IJWLayer::GuiControlProfile::FillColorNA::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFillColorNA = ColorI(value->R, value->G, value->B, value->A);
}

int IJWLayer::GuiControlProfile::Border::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mBorder;
}

void IJWLayer::GuiControlProfile::Border::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mBorder = value;
}

int IJWLayer::GuiControlProfile::BorderThickness::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mBorderThickness;
}

void IJWLayer::GuiControlProfile::BorderThickness::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mBorderThickness = value;
}

Color^ IJWLayer::GuiControlProfile::BorderColor::get()
{
   if (!IsAlive())
      return nullptr;
   return Color::FromArgb(GetObjectPtr()->mBorderColor.red,
      GetObjectPtr()->mBorderColor.green,
      GetObjectPtr()->mBorderColor.blue,
      GetObjectPtr()->mBorderColor.alpha);
}

void IJWLayer::GuiControlProfile::BorderColor::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mBorderColor = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::BorderColorHL::get()
{
   if (!IsAlive())
      return nullptr;
   return Color::FromArgb(GetObjectPtr()->mBorderColorHL.red,
      GetObjectPtr()->mBorderColorHL.green,
      GetObjectPtr()->mBorderColorHL.blue,
      GetObjectPtr()->mBorderColorHL.alpha);
}

void IJWLayer::GuiControlProfile::BorderColorHL::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mBorderColorHL = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::BorderColorNA::get()
{
   if (!IsAlive())
      return nullptr;
   return Color::FromArgb(GetObjectPtr()->mBorderColorNA.red,
      GetObjectPtr()->mBorderColorNA.green,
      GetObjectPtr()->mBorderColorNA.blue,
      GetObjectPtr()->mBorderColorNA.alpha);
}

void IJWLayer::GuiControlProfile::BorderColorNA::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mBorderColorNA = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::BevelColorHL::get()
{
   if (!IsAlive())
      return nullptr;
   return Color::FromArgb(GetObjectPtr()->mBevelColorHL.red,
      GetObjectPtr()->mBevelColorHL.green,
      GetObjectPtr()->mBevelColorHL.blue,
      GetObjectPtr()->mBevelColorHL.alpha);
}

void IJWLayer::GuiControlProfile::BevelColorHL::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mBevelColorHL = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::BevelColorLL::get()
{
   if (!IsAlive())
      return nullptr;
   return Color::FromArgb(GetObjectPtr()->mBevelColorLL.red,
      GetObjectPtr()->mBevelColorLL.green,
      GetObjectPtr()->mBevelColorLL.blue,
      GetObjectPtr()->mBevelColorLL.alpha);
}

void IJWLayer::GuiControlProfile::BevelColorLL::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mBevelColorLL = ColorI(value->R, value->G, value->B, value->A);
}

String^ IJWLayer::GuiControlProfile::FontType::get()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->mFontType);
}

void IJWLayer::GuiControlProfile::FontType::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->mFontType = _value;
}

int IJWLayer::GuiControlProfile::FontSize::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->mFontSize;
}

void IJWLayer::GuiControlProfile::FontSize::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFontSize = value;
}

int IJWLayer::GuiControlProfile::FontCharset::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->mFontCharset;
}

void IJWLayer::GuiControlProfile::FontCharset::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFontCharset = (EngineFontCharset)value;
}

Color^ IJWLayer::GuiControlProfile::FontColors::get(int index)
{
   if (!IsAlive())
      return nullptr;
   ColorI col = GetObjectPtr()->mFontColors[index];
   return Color::FromArgb(col.red, col.green, col.blue, col.alpha);
}

void IJWLayer::GuiControlProfile::FontColors::set(int index, Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFontColors[index] = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::FontColor::get()
{
   if (!IsAlive())
      return nullptr;
   ColorI col = GetObjectPtr()->mFontColors[EngineGuiControlProfile::BaseColor];
   return Color::FromArgb(col.red, col.green, col.blue, col.alpha);
}

void IJWLayer::GuiControlProfile::FontColor::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFontColors[EngineGuiControlProfile::BaseColor] = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::FontColorHL::get()
{
   if (!IsAlive())
      return nullptr;
   ColorI col = GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorHL];
   return Color::FromArgb(col.red, col.green, col.blue, col.alpha);
}

void IJWLayer::GuiControlProfile::FontColorHL::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorHL] = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::FontColorNA::get()
{
   if (!IsAlive())
      return nullptr;
   ColorI col = GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorNA];
   return Color::FromArgb(col.red, col.green, col.blue, col.alpha);
}

void IJWLayer::GuiControlProfile::FontColorNA::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorNA] = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::FontColorSEL::get()
{
   if (!IsAlive())
      return nullptr;
   ColorI col = GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorSEL];
   return Color::FromArgb(col.red, col.green, col.blue, col.alpha);
}

void IJWLayer::GuiControlProfile::FontColorSEL::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorSEL] = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::FontColorLink::get()
{
   if (!IsAlive())
      return nullptr;
   ColorI col = GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorUser0];
   return Color::FromArgb(col.red, col.green, col.blue, col.alpha);
}

void IJWLayer::GuiControlProfile::FontColorLink::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorUser0] = ColorI(value->R, value->G, value->B, value->A);
}

Color^ IJWLayer::GuiControlProfile::FontColorLinkHL::get()
{
   if (!IsAlive())
      return nullptr;
   ColorI col = GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorUser1];
   return Color::FromArgb(col.red, col.green, col.blue, col.alpha);
}

void IJWLayer::GuiControlProfile::FontColorLinkHL::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mFontColors[EngineGuiControlProfile::ColorUser1] = ColorI(value->R, value->G, value->B, value->A);
}

int IJWLayer::GuiControlProfile::Justify::get()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->mAlignment;
}

void IJWLayer::GuiControlProfile::Justify::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mAlignment = (EngineGuiControlProfile::AlignmentType)value;
}

IJWLayer::Point2I^ IJWLayer::GuiControlProfile::TextOffset::get()
{
   if (!IsAlive())
      return nullptr;
   return gcnew Point2I(GetObjectPtr()->mTextOffset.x, GetObjectPtr()->mTextOffset.y);
}

void IJWLayer::GuiControlProfile::TextOffset::set(IJWLayer::Point2I^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mTextOffset = EnginePoint2I(value->x, value->y);
}

bool IJWLayer::GuiControlProfile::AutoSizeWidth::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mAutoSizeWidth;
}

void IJWLayer::GuiControlProfile::AutoSizeWidth::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mAutoSizeWidth = value;
}

bool IJWLayer::GuiControlProfile::AutoSizeHeight::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mAutoSizeHeight;
}

void IJWLayer::GuiControlProfile::AutoSizeHeight::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mAutoSizeHeight = value;
}

bool IJWLayer::GuiControlProfile::ReturnTab::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mReturnTab;
}

void IJWLayer::GuiControlProfile::ReturnTab::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mReturnTab = value;
}

bool IJWLayer::GuiControlProfile::NumbersOnly::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->mNumbersOnly;
}

void IJWLayer::GuiControlProfile::NumbersOnly::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mNumbersOnly = value;
}

Color^ IJWLayer::GuiControlProfile::CursorColor::get()
{
   if (!IsAlive())
      return nullptr;
   ColorI col = GetObjectPtr()->mCursorColor;
   return Color::FromArgb(col.red, col.green, col.blue, col.alpha);
}

void IJWLayer::GuiControlProfile::CursorColor::set(Color^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mCursorColor = ColorI(value->R, value->G, value->B, value->A);
}

String^ IJWLayer::GuiControlProfile::Bitmap::get()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->mBitmapName);
}

void IJWLayer::GuiControlProfile::Bitmap::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->mBitmapName = _value;
}

IJWLayer::AudioAsset^ IJWLayer::GuiControlProfile::SoundButtonDown::get()
{
   if (!IsAlive())
      return nullptr;
   return AudioAsset::Wrap((EngineAudioAsset*)GetObjectPtr()->mSoundButtonDown);
}

void IJWLayer::GuiControlProfile::SoundButtonDown::set(AudioAsset^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mSoundButtonDown = AssetPtr<EngineAudioAsset>(value->GetObjectPtr()->getAssetId());
}

IJWLayer::AudioAsset^ IJWLayer::GuiControlProfile::SoundButtonOver::get()
{
   if (!IsAlive())
      return nullptr;
   return AudioAsset::Wrap((EngineAudioAsset*)GetObjectPtr()->mSoundButtonOver);
}

void IJWLayer::GuiControlProfile::SoundButtonOver::set(AudioAsset^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mSoundButtonOver = AssetPtr<EngineAudioAsset>(value->GetObjectPtr()->getAssetId());
}


IJWLayer::GuiControlProfile^ IJWLayer::GuiControlProfile::ProfileForChildren::get()
{
   if (!IsAlive())
      return nullptr;
   return GuiControlProfile::Wrap(GetObjectPtr()->mProfileForChildren);
}

void IJWLayer::GuiControlProfile::ProfileForChildren::set(GuiControlProfile^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->mProfileForChildren = value->GetObjectPtr();
}

IJWLayer::Point2I^ IJWLayer::GuiCursor::HotSpot::get()
{
   if (!IsAlive())
      return nullptr;
   return gcnew Point2I(GetObjectPtr()->getHotSpot().x, GetObjectPtr()->getHotSpot().y);
}

void IJWLayer::GuiCursor::HotSpot::set(IJWLayer::Point2I^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setHotSpot(EnginePoint2I(value->x, value->y));
}

IJWLayer::Point2F^ IJWLayer::GuiCursor::RenderOffset::get()
{
   if (!IsAlive())
      return nullptr;
   return gcnew Point2F(GetObjectPtr()->getRenderOffset().x, GetObjectPtr()->getRenderOffset().y);
}

void IJWLayer::GuiCursor::RenderOffset::set(IJWLayer::Point2F^ value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setRenderOffset(EnginePoint2F(value->x, value->y));
}

String^ IJWLayer::GuiCursor::BitmapName::get()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->getBitmapName());
}

void IJWLayer::GuiCursor::BitmapName::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setBitmapName(StringTable->insert(_value));
}

bool IJWLayer::PopupMenu::IsPopup::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getIsPopup();
}

void IJWLayer::PopupMenu::IsPopup::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setIsPopup(value);
}