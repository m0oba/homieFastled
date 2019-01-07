#include "Global.h"
#include "FastLED.h"

void setColor(int inR, int inG, int inB) 
{
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].red   = inR;
    leds[i].green = inG;
    leds[i].blue  = inB;
  }

  FastLED.show();

  Serial.println("Setting LEDs:");
  Serial.print("r: ");
  Serial.print(inR);
  Serial.print(", g: ");
  Serial.print(inG);
  Serial.print(", b: ");
  Serial.println(inB);
}

void showleds() 
{
    delay(1);
    if (stateOn) 
    {
        FastLED.setBrightness(brightness);  //EXECUTE EFFECT COLOR
        FastLED.show();
        if (transitionTime > 0 && transitionTime < 250) //Sets animation speed based on receieved value
        {  
            FastLED.delay(transitionTime / 10 * delayMultiplier); //1000 / transitionTime);
            //delay(10*transitionTime);
        }
    }
    else if (startFade) 
    {
        setColor(0, 0, 0);
        startFade = false;
    }
}

void temp2rgb(unsigned int kelvin) 
{
    int tmp_internal = kelvin / 100.0;
    
    // red 
    if (tmp_internal <= 66) 
    {
        red = 255;
    } 
    else 
    {
        float tmp_red = 329.698727446 * pow(tmp_internal - 60, -0.1332047592);
        if (tmp_red < 0) 
        {
            red = 0;
        } 
        else if (tmp_red > 255) 
        {
            red = 255;
        } 
        else 
        {
            red = tmp_red;
        }
    }
    
    // green
    if (tmp_internal <=66)
    {
        float tmp_green = 99.4708025861 * log(tmp_internal) - 161.1195681661;
        if (tmp_green < 0) {
            green = 0;
        } else if (tmp_green > 255) {
            green = 255;
        } else {
            green = tmp_green;
        }
    } 
    else 
    {
        float tmp_green = 288.1221695283 * pow(tmp_internal - 60, -0.0755148492);
        if (tmp_green < 0) 
        {
            green = 0;
        } 
        else if (tmp_green > 255) 
        {
            green = 255;
        } 
        else 
        {
            green = tmp_green;
        }
    }
    
    // blue
    if (tmp_internal >=66) 
    {
        blue = 255;
    } else if (tmp_internal <= 19) 
    {
        blue = 0;
    } else {
        float tmp_blue = 138.5177312231 * log(tmp_internal - 10) - 305.0447927307;
        if (tmp_blue < 0) {
            blue = 0;
        } else if (tmp_blue > 255) {
            blue = 255;
        } else {
            blue = tmp_blue;
        }
    }
}

void flash_fade()
{
    if (flash) 
    {
        if (startFlash) 
        {
            startFlash = false;
            flashStartTime = millis();
        }

        if ((millis() - flashStartTime) <= flashLength) 
        {
            if ((millis() - flashStartTime) % 1000 <= 500) 
            {
            setColor(flashRed, flashGreen, flashBlue);
            }
            else 
            {
                setColor(0, 0, 0);
                // If you'd prefer the flashing to happen "on top of"
                // the current color, uncomment the next line.
                // setColor(realRed, realGreen, realBlue);
            }
        }
        else 
        {
        flash = false;
        strip_effect = strip_oldeffect;
            if (onbeforeflash) 
            { //keeps light off after flash if light was originally off
                setColor(realRed, realGreen, realBlue);
            }
            else 
            {
                stateOn = false;
                setColor(0, 0, 0);
            }
        }
    }

}

int calculateStep(int prevValue, int endValue) 
{
    int step = endValue - prevValue; // What's the overall gap?
    if (step) 
    {                      // If its non-zero,
        step = 1020 / step;          //   divide by 1020
    }
    return step;
}
/* The next function is calculateVal. When the loop value, i,
   reaches the step size appropriate for one of the
   colors, it increases or decreases the value of that color by 1.
   (R, G, and B are each calculated separately.)
*/
int calculateVal(int step, int val, int i) 
{
  if ((step) && i % step == 0) { // If step is non-zero and its time to change a value,
    if (step > 0) {              //   increment the value if step is positive...
      val += 1;
    }
    else if (step < 0) {         //   ...or decrement it if step is negative
      val -= 1;
    }
}

  // Defensive driving: make sure val stays in the range 0-255
  if (val > 255) {
    val = 255;
  }
  else if (val < 0) {
    val = 0;
  }

  return val;
}
/********************************** START FADE************************************************/
void fadeall() 
{
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(250);  //for CYCLon
  }
}

/********************************** START FIRE **********************************************/
void Fire2012WithPalette()
{
  // Array of temperature readings at each simulation cell
  static byte heat[NUM_LEDS];

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < NUM_LEDS; i++) {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = NUM_LEDS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if ( random8() < SPARKING ) {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160, 255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for ( int j = 0; j < NUM_LEDS; j++) {
    // Scale the heat value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if ( gReverseDirection ) {
      pixelnumber = (NUM_LEDS - 1) - j;
    } else {
      pixelnumber = j;
    }
    leds[pixelnumber] = color;
  }
}



/********************************** START ADD GLITTER *********************************************/
void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}



/********************************** START ADD GLITTER COLOR ****************************************/
void addGlitterColor( fract8 chanceOfGlitter, int red, int green, int blue)
{
  if ( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB(red, green, blue);
  }
}

void colorwaves( CRGB* ledarray, uint16_t numleds, CRGBPalette16& palette) 
{
  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;
 
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 300, 1500);
  
  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5,9);
  uint16_t brightnesstheta16 = sPseudotime;
  
  for( uint16_t i = 0 ; i < numleds; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;
    uint16_t h16_128 = hue16 >> 7;
    if( h16_128 & 0x100) {
      hue8 = 255 - (h16_128 >> 1);
    } else {
      hue8 = h16_128 >> 1;
    }

    brightnesstheta16  += brightnessthetainc16;
    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);
    
    uint8_t index = hue8;
    //index = triwave8( index);
    index = scale8( index, 240);

    CRGB newcolor = ColorFromPalette( palette, index, bri8);

    uint16_t pixelnumber = i;
    pixelnumber = (numleds-1) - pixelnumber;
    
    nblend( ledarray[pixelnumber], newcolor, 128);
  }
}

