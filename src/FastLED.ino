#include <Homie.h>
#include "Inits.h"
#include "Global.h"
#include "Function.h"
#include "Effect.h"
#include "FastLED.h"

HomieNode StripNode("strip", "Strip", "STRIP");

bool switchOnHandler(const HomieRange& range, const String& value) 
{
  if (value != "true" && value != "false") return false;
  strip_power = (value == "true");
  StripNode.setProperty("power").send(value);
  Homie.getLogger() << "Light is " << (strip_power ? "on" : "off") << endl;
  return true;
}

bool effectHandler(const HomieRange& range, const String& value)
{
  strip_mode = "effect";
  strip_effect = value;
  StripNode.setProperty("mode").send("effect");
  StripNode.setProperty("effect").send(value);
  Homie.getLogger() << "effect is " << value << endl;
  Serial.println(value);
  return true;
}

bool posteffectHandler(const HomieRange& range, const String& value)
{
  strip_posteffect = value;
  StripNode.setProperty("posteffect").send(value);
  Homie.getLogger() << "posteffect is " << value << endl;
  Serial.println(value);
  return true;
}

bool brightnessHandler(const HomieRange& range, const String& value)
{
  bright = value.toInt();
  StripNode.setProperty("brightness").send(value);
  Homie.getLogger() << "brightness is " << value << endl;
  return true;
}

bool colorHandler(const HomieRange& range, const String& value)
{
  strip_mode = "solid";
  String h =  getValue(value, ',', 0);
  String s =  getValue(value, ',', 1);
  String v =  getValue(value, ',', 2);
  int hue = map(h.toInt(),0,360,0,255);
  int sat = map(s.toInt(),0,100,0,255);
  int val = map(v.toInt(),0,100,0,255);
  CHSV colorHSV( hue, sat, val);
  colorRGB = colorHSV;
  StripNode.setProperty("mode").send("solid");
  StripNode.setProperty("color").send(value);
  Homie.getLogger() << "color is " << "solid :" << hue <<","<< sat <<","<< val << endl;
  return true;
}

bool gradientHandler(const HomieRange& range, const String& value)
{
  strip_mode = "gradient";
  //gradient_playlist = false;
  gCurrentPaletteNumber = value.toInt();
  StripNode.setProperty("gradient").send(value);
  return true;
}
bool secondsHandler(const HomieRange& range, const String& value)
{  
  PlaylistSecond = value.toInt();
  //gradient_playlist = !(value=="0");
  Homie.getLogger() << "seconds is " << value << endl;
  return true;
}

bool modeHandler (const HomieRange& range, const String& value)
{
  strip_mode = value;
  StripNode.setProperty("mode").send(value);
  return true;
}

void setup() 
{
  Serial.begin(115200);
  Serial << endl << endl;
  Homie_setFirmware("homie-fastled", "1.0.0");
  
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  InitFastled();
  
  
  gPal = HeatColors_p; //for FIRE



  StripNode.advertise("power")
            .setName("Power")
            .setDatatype("boolean")
            .settable(switchOnHandler);
  
  StripNode.advertise("brightness")
                .setName("Brightness")
                .setDatatype("integer")
                .setUnit("%")
                .setFormat("0:100")
                .settable(brightnessHandler);
  
  StripNode.advertise("color")
            .setName("Color")
            .setDatatype("color")
            .setFormat("hsv")
            .settable(colorHandler);

  StripNode.advertise("effect")
            .setName("Effect")
            .setDatatype("string")
            .settable(effectHandler);
  
  StripNode.advertise("posteffect")
            .setName("Posteffect")
            .setDatatype("string")
            .settable(posteffectHandler);
  
  StripNode.advertise("gradient")
              .setName("Gradient")
              .setDatatype("string")
              .settable(gradientHandler);
  
  StripNode.advertise("mode")
              .setName("Mode")
              .setDatatype("string")
              .settable(modeHandler);
  
  StripNode.advertise("seconds")
              .setName("Seconds")
              .setDatatype("integer")
              .settable(secondsHandler);
                                    
  Homie.setup();
}

void loop() 
{
  yield(); // Avoid crashes on ESP8266
  Homie.loop();
  random16_add_entropy(random(65535));

  if (strip_power) 
  {
    EVERY_N_MILLISECONDS( 20 ) 
    {
      gHue++;  // slowly cycle the "base color" through the rainbow
    }
    
    if (gradient_playlist)
    {
      EVERY_N_SECONDS( PlaylistSecond ) 
      //uint8_t gCurrentPaletteNumber_tmp = addmod8( gCurrentPaletteNumber, 1, gGradientPaletteCount);
      gCurrentPaletteNumber  = addmod8( gCurrentPaletteNumber, 1, gGradientPaletteCount);
    }
  
    if (strip_mode == "solid") 
    {
      fill_solid(leds, NUM_LEDS, colorRGB);
    }

    if (strip_mode == "effect") 
    {
      effect1();
    }

    if (strip_mode == "gradient")
    {
      gTargetPalette = gGradientPalettes[ gCurrentPaletteNumber ];
      // slowly blend the current cpt-city gradient palette to the next
      EVERY_N_MILLISECONDS(40) 
      {
        nblendPaletteTowardPalette( gCurrentPalette, gTargetPalette, 16); 
      } 
    }
  
  // Posteffect
    if (strip_posteffect == "colorwaves")
    {
      colorwaves( leds, NUM_LEDS, gCurrentPalette);
    }
    else if (strip_posteffect == "normal")
    {
      
    }
    else if (strip_posteffect == "noises")
    {
      add_noises();
    }
    else if (strip_posteffect == "glitter")
    {
      add_glitter(5, 3 );
    }
  }
  else
  {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    Homie.getLogger() << "off5" << endl;
  }
  
  showleds() ;
  // insert a delay to keep the framerate modest
  delay(1000 / FRAMES_PER_SECOND);
}
