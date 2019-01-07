#include "Global.h"
#include "FastLED.h"
#include "Palettes.h"

/////////////////////////////////////////  
//////DrZzs custom effects//////////////
///////////////////////////////////////
void effect1 ()
{

    if (strip_effect == "christmas") 
    {                                  // colored stripes pulsing in Shades of GREEN and RED 
        uint8_t BeatsPerMinute = 62;
        CRGBPalette16 palette = bhw2_xmas_gp;
        uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
        for( int i = 0; i < NUM_LEDS; i++) { //9948
        leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
    }
        if (transitionTime == 0 ) {
        transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();  
    }
    
    // colored stripes pulsing in Shades of GREEN
    if (strip_effect == "st_patty") 
    {                                  
        uint8_t BeatsPerMinute = 62;
        CRGBPalette16 palette = bhw2_greenman_gp;
        uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
        for( int i = 0; i < NUM_LEDS; i++) 
        { //9948
            leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
        }
        if (transitionTime == 0 ) 
        {
            transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();  
    }

    if (strip_effect == "valentine") 
    {                                  // colored stripes pulsing in Shades of PINK and RED 
        uint8_t BeatsPerMinute = 62;
        CRGBPalette16 palette = bhw2_redrosey_gp;
        uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
        for( int i = 0; i < NUM_LEDS; i++) 
        { //9948
        leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
        }
        if (transitionTime == 0 ) 
        {
            transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();
    }  


    if (strip_effect == "turkey_day") 
    {                                  // colored stripes pulsing in Shades of Brown and ORANGE 
        uint8_t BeatsPerMinute = 62;
        CRGBPalette16 palette = bhw2_thanks_gp;
        uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
        for( int i = 0; i < NUM_LEDS; i++) 
        { //9948
            leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
        }
        if (transitionTime == 0 ) 
        {
            transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();
    }

    if (strip_effect == "thanksgiving") 
    {                                  // colored stripes pulsing in Shades of Red and ORANGE and Green 
        static uint8_t startIndex = 0;
        startIndex = startIndex + 1; /* higher = faster motion */

        fill_palette( leds, NUM_LEDS,
                    startIndex, 16, /* higher = narrower stripes */
                    ThxPalettestriped, 255, LINEARBLEND);
        if (transitionTime == 0 ) 
        {
            transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();  
    }
  
    if (strip_effect == "france") 
    {                                  // colored stripes pulsing in Shades of Red White & Blue 
        uint8_t BeatsPerMinute = 62;
        CRGBPalette16 palette = bhw3_41_gp;
        uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
        for( int i = 0; i < NUM_LEDS; i++) 
        { //9948
            leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
        }
        if (transitionTime == 0 ) 
        {
            transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();  
    }

    if (strip_effect == "independence") 
    {                        // colored stripes of Red White & Blue
        static uint8_t startIndex = 0;
        startIndex = startIndex + 1; /* higher = faster motion */

        fill_palette( leds, NUM_LEDS,
                    startIndex, 16, /* higher = narrower stripes */
                    IndPalettestriped, 255, LINEARBLEND);
        if (transitionTime == 0 ) 
        {
        transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();  
    }


  if (strip_effect == "halloween") {                                  // colored stripes pulsing in Shades of Purple and Orange
    uint8_t BeatsPerMinute = 62;
    CRGBPalette16 palette = Orange_to_Purple_gp;
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
    if (transitionTime == 0 ) {
      transitionTime = 30;
    }
    delayMultiplier = 1;
    showleds();  
    }

  if (strip_effect == "go_lions") {                                  // colored stripes pulsing in Shades of <strike>Maize and</strike> Blue & White (FTFY DrZZZ :-P)
    uint8_t BeatsPerMinute = 62;
    CRGBPalette16 palette = PSU_gp;
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
    if (transitionTime == 0 ) {
      transitionTime = 30;
    }
    delayMultiplier = 1;
    showleds();  
    }

  if (strip_effect == "hail") {
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* higher = faster motion */

    fill_palette( leds, NUM_LEDS,
                  startIndex, 16, /* higher = narrower stripes */
                  hailPalettestriped, 255, LINEARBLEND);
    if (transitionTime == 0 ) {
      transitionTime = 30;
    }
    delayMultiplier = 1;
    showleds();  
    }
  
  if (strip_effect == "touchdown") {                 //<strike>Maize and</strike> Blue & White with POLICE ALL animation
    idex++;
    if (idex >= NUM_LEDS) {
      idex = 0;
    }
    int idexY = idex;
    int idexB = antipodal_index(idexY);
    leds[idexY] = CRGB::Blue; //CHSV(thishuehail, thissat, 255);
    leds[idexB] = CRGB::White; //CHSV(thathue, thissat, 255);
    if (transitionTime == 0 ) {
      transitionTime = 30;
    }
    delayMultiplier = 1;
    showleds();  
  }

  if (strip_effect == "punkin") 
  {
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* higher = faster motion */

    fill_palette( leds, NUM_LEDS,
                  startIndex, 16, /* higher = narrower stripes */
                  HalloweenPalettestriped, 255, LINEARBLEND);
    if (transitionTime == 0 ) {
      transitionTime = 30;
    }
    delayMultiplier = 1;
    showleds();  
  }

    if (strip_effect == "lovey_day") 
    {                 //Valentine's Day colors (TWO COLOR SOLID)
    idex++;
    if (idex >= NUM_LEDS) {
      idex = 0;
    }
    int idexR = idex;
    int idexB = antipodal_index(idexR);
    int thathue = (thishueLovey + 244) % 255;
    leds[idexR] = CHSV(thishueLovey, thissat, 255);
    leds[idexB] = CHSV(thathue, thissat, 255);
    if (transitionTime == 0 ) {
      transitionTime = 30;
    }
    delayMultiplier = 1;
    showleds();  
  }

  if (strip_effect == "holly_jolly") 
  {
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* higher = faster motion */

    fill_palette( leds, NUM_LEDS,
                  startIndex, 16, /* higher = narrower stripes */
                  HJPalettestriped, 255, LINEARBLEND);
    if (transitionTime == 0 ) {
      transitionTime = 30;
    }
    delayMultiplier = 1;
    showleds();                  
  }

  //EFFECT BPM
  if (strip_effect == "bpm") 
  {
    uint8_t BeatsPerMinute = 62;
    CRGBPalette16 palette = PartyColors_p;
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for ( int i = 0; i < NUM_LEDS; i++) { //9948
      leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
    }
    if (transitionTime == 0 ) {
      transitionTime = 30;
    }
    delayMultiplier = 1;
    showleds();
  }


  //EFFECT Candy Cane
    if (strip_effect == "candy_cane") 
    {
        static uint8_t startIndex = 0;
        startIndex = startIndex + 1; /* higher = faster motion */
        fill_palette( leds, NUM_LEDS,
                    startIndex, 16, /* higher = narrower stripes */
                    currentPalettestriped, 255, LINEARBLEND);
        if (transitionTime == 0 ) {
        transitionTime = 0;
        }
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT CONFETTI
    if (strip_effect == "confetti" ) 
    {
        fadeToBlackBy( leds, NUM_LEDS, 25);
        int pos = random16(NUM_LEDS);
        leds[pos] += CRGB(realRed + random8(64), realGreen, realBlue);
        if (transitionTime == 0 ) {
        transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT CYCLON RAINBOW
    if (strip_effect == "cyclon_rainbow") 
    {                    //Single Dot Down
        static uint8_t hue = 0;
        // First slide the led in one direction
        for (int i = 0; i < NUM_LEDS; i++) {
        // Set the i'th led to red
        leds[i] = CHSV(hue++, 255, 255);
        // Show the leds
        delayMultiplier = 1;
        showleds();
        // now that we've shown the leds, reset the i'th led to black
        // leds[i] = CRGB::Black;
        fadeall();
        // Wait a little bit before we loop around and do it again
        delay(10);
        }
        for (int i = (NUM_LEDS) - 1; i >= 0; i--) {
        // Set the i'th led to red
        leds[i] = CHSV(hue++, 255, 255);
        // Show the leds
        delayMultiplier = 1;
        showleds();
        // now that we've shown the leds, reset the i'th led to black
        // leds[i] = CRGB::Black;
        fadeall();
        // Wait a little bit before we loop around and do it again
        delay(10);
        }
    }


    //EFFECT DOTS
    if (strip_effect == "dots") 
    {
        uint8_t inner = beatsin8(bpm, NUM_LEDS / 4, NUM_LEDS / 4 * 3);
        uint8_t outer = beatsin8(bpm, 0, NUM_LEDS - 1);
        uint8_t middle = beatsin8(bpm, NUM_LEDS / 3, NUM_LEDS / 3 * 2);
        leds[middle] = CRGB::Purple;
        leds[inner] = CRGB::Blue;
        leds[outer] = CRGB::Aqua;
        nscale8(leds, NUM_LEDS, fadeval);

        if (transitionTime == 0 ) {
        transitionTime = 30;
        }    
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT FIRE
    if (strip_effect == "fire") 
    {
        Fire2012WithPalette();
        if (transitionTime == 0 ) {
        transitionTime = 150;
        }
        delayMultiplier = 2;
        showleds();
    }

    random16_add_entropy( random8());


    //EFFECT Glitter
    if (strip_effect == "glitter") 
    {
        fadeToBlackBy( leds, NUM_LEDS, 20);
        addGlitterColor(80, realRed, realGreen, realBlue);
        if (transitionTime == 0 ) {
        transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT JUGGLE
    if (strip_effect == "juggle" ) 
    {                           // eight colored dots, weaving in and out of sync with each other
        fadeToBlackBy(leds, NUM_LEDS, 20);
        for (int i = 0; i < 8; i++) {
        leds[beatsin16(i + 7, 0, NUM_LEDS - 1  )] |= CRGB(realRed, realGreen, realBlue);
        }
        if (transitionTime == 0 ) {
        transitionTime = 130;
        }
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT LIGHTNING
    if (strip_effect == "lightning") 
    {
        twinklecounter = twinklecounter + 1;                     //Resets strip if previous animation was running
        if (twinklecounter < 2) {
        FastLED.clear();
        FastLED.show();
        }
        ledstart = random16(NUM_LEDS);           // Determine starting location of flash
        ledlen = random16(NUM_LEDS - ledstart);  // Determine length of flash (not to go beyond NUM_LEDS-1)
        for (int flashCounter = 0; flashCounter < random8(3, flashes); flashCounter++) {
        if (flashCounter == 0) dimmer = 5;    // the brightness of the leader is scaled down by a factor of 5
        else dimmer = random8(1, 3);          // return strokes are brighter than the leader
        fill_solid(leds + ledstart, ledlen, CHSV(255, 0, 255 / dimmer));
        showleds();    // Show a section of LED's
        delay(random8(4, 10));                // each flash only lasts 4-10 milliseconds
        fill_solid(leds + ledstart, ledlen, CHSV(255, 0, 0)); // Clear the section of LED's
        showleds();
        if (flashCounter == 0) delay (130);   // longer delay until next flash after the leader
        delay(50 + random8(100));             // shorter delay between strokes
        }
        delay(random8(frequency) * 100);        // delay between strikes
        if (transitionTime == 0 ) {
        transitionTime = 0;
        }
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT POLICE ALL
    if (strip_effect == "police_all") 
    {                 //POLICE LIGHTS (TWO COLOR SOLID)
        idex++;
        if (idex >= NUM_LEDS) {
        idex = 0;
        }
        int idexR = idex;
        int idexB = antipodal_index(idexR);
        int thathue = (thishuepolice + 160) % 255;
        leds[idexR] = CHSV(thishuepolice, thissat, 255);
        leds[idexB] = CHSV(thathue, thissat, 255);
        if (transitionTime == 0 ) {
        transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();
    }

    //EFFECT POLICE ONE
    if (strip_effect == "police_one") 
    {
        idex++;
        if (idex >= NUM_LEDS) {
        idex = 0;
        }
        int idexR = idex;
        int idexB = antipodal_index(idexR);
        int thathue = (thishuepolice + 160) % 255;
        for (int i = 0; i < NUM_LEDS; i++ ) {
        if (i == idexR) {
            leds[i] = CHSV(thishuepolice, thissat, 255);
        }
        else if (i == idexB) {
            leds[i] = CHSV(thathue, thissat, 255);
        }
        else {
            leds[i] = CHSV(0, 0, 0);
        }
        }
        if (transitionTime == 0 ) {
        transitionTime = 30;
        }
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT RAINBOW
    if (strip_effect == "rainbow") 
    {
        // FastLED's built-in rainbow generator
        fill_rainbow(leds, NUM_LEDS, thishue, deltahue);
        if (transitionTime == 0 ) {
        transitionTime = 130;
        }
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT RAINBOW WITH GLITTER
    if (strip_effect == "rainbow_with_glitter") 
    {               // FastLED's built-in rainbow generator with Glitter
        thishue++;
        fill_rainbow(leds, NUM_LEDS, thishue, deltahue);
        addGlitter(80);
        if (transitionTime == 0 ) {
        transitionTime = 130;
        }
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT SINELON
    if (strip_effect == "sinelon") 
    {
        fadeToBlackBy( leds, NUM_LEDS, 20);
        int pos = beatsin16(13, 0, NUM_LEDS - 1);
        leds[pos] += CRGB(realRed, realGreen, realBlue);
        if (transitionTime == 0 ) {
        transitionTime = 150;
        }
        delayMultiplier = 1;
        showleds();
    }


    //EFFECT TWINKLE
    if (strip_effect == "twinkle") 
    {
        twinklecounter = twinklecounter + 1;
        if (twinklecounter < 2) {                               //Resets strip if previous animation was running
        FastLED.clear();
        FastLED.show();
        }
        const CRGB lightcolor(8, 7, 1);
        for ( int i = 0; i < NUM_LEDS; i++) {
        if ( !leds[i]) continue; // skip black pixels
        if ( leds[i].r & 1) { // is red odd?
            leds[i] -= lightcolor; // darken if red is odd
        } else {
            leds[i] += lightcolor; // brighten if red is even
        }
        }
        if ( random8() < DENSITY) {
        int j = random16(NUM_LEDS);
        if ( !leds[j] ) leds[j] = lightcolor;
        }

        if (transitionTime == 0 ) {
        transitionTime = 0;
        }
        delayMultiplier = 1;
        showleds();
    }

    //EFFECT CHRISTMAS ALTERNATE
    if (strip_effect == "christmas_alternate") 
    {
        for (int i = 0; i < NUM_LEDS; i++) {
            if ((toggle + i) % 2 == 0) {
            leds[i] = CRGB::Crimson;
            }
            else {
            leds[i] = CRGB::DarkGreen;
            }
        }
        /*if (toggle == 0) {
            toggle = 1;
        }
        else {
            toggle = 0;
        }*/ toggle=(toggle + 1) % 2;
        if (transitionTime == 0 ) {
        transitionTime = 130;
        }
        delayMultiplier = 30;
        showleds();  
        fadeall(); 
        //delay(200);
    }

    //EFFECT RANDOM STARS
    if (strip_effect == "random_stars") 
    {
    /*     if(toggle==0)
        {        
            for (int i = 0; i < NUM_STARS; i++)
            {
            stars[i] = random(0, NUM_LEDS);
            }
            fill_solid (&(leds[0]), NUM_LEDS, CHSV(160, 255, brightness));
            toggle = 1;
        }
        else if (toggle == 1)
        {
            for (int j = 0; j < NUM_STARS; j++)
            {
            leds[stars[j]] ++;
            }
            if (leds[stars[0]].r == 255)
            {
            toggle = -1;
            }
        }
        else if (toggle == -1)
        {
            for (int j = 0; j < NUM_STARS; j++)
            {
            leds[stars[j]] --; //.fadeLightBy(i);
            }
            if (leds[stars[0]] <= CHSV(160, 255, brightness))
            {
            toggle = 0;
            }
        }
        showleds();   
    */
        fadeUsingColor( leds, NUM_LEDS, CRGB::Blue);
        int pos = random16(NUM_LEDS);
        leds[pos] += CRGB(realRed + random8(64), realGreen, realBlue);
        addGlitter(80);
        if (transitionTime == 0 ) {
        transitionTime = 30;
        }
        delayMultiplier = 6;
        //delay(60);
        showleds();
            
    }

    //EFFECT "Sine Hue"
    if (strip_effect == "sine_hue") 
    {
        static uint8_t hue_index = 0;
        static uint8_t led_index = 0;
        if (led_index >= NUM_LEDS) {  //Start off at 0 if the led_index was incremented past the segment size in some other effect
            led_index = 0;
        }
        for (int i = 0; i < NUM_LEDS; i = i + 1)
        {
            leds[i] = CHSV(hue_index, 255, 255 - int(abs(sin(float(i + led_index) / NUM_LEDS * 2 * 3.14159) * 255)));
        }

        led_index++,hue_index++;

        if (hue_index >= 255) {
            hue_index = 0;
        }
        delayMultiplier = 2;
        showleds();        
    }


    //EFFECT "Full Hue"
    if (strip_effect == "full_hue") 
    {
        static uint8_t hue_index = 0;
        fill_solid(leds, NUM_LEDS, CHSV(hue_index, 255, 255));
        hue_index++;

        if (hue_index >= 255) {
            hue_index = 0;
        }
        delayMultiplier = 2;
        showleds();        
    }
    

    //EFFECT "Breathe"
    if (strip_effect == "breathe") 
    {
        static bool toggle;
        static uint8_t brightness_index = 0;
        fill_solid(leds, NUM_LEDS,CHSV(thishue,255,brightness_index));
        if (brightness_index >= 255) {
            toggle=0;        
        }
        else if (brightness_index <= 0)
        {
            toggle=1;
        }

        if (toggle)
        {
            brightness_index++;
        }
        else
        {
        brightness_index--;
        }
        
        delayMultiplier = 2;
        showleds();        
    }


    //EFFECT "Hue Breathe"
    if (strip_effect == "hue_breathe") 
    {
        static uint8_t hue_index = 0;
        static bool toggle = 1;
        static uint8_t brightness_index = 0;
        fill_solid(leds, NUM_LEDS, CHSV(hue_index, 255, brightness_index));
        if (brightness_index >= 255) {
            toggle=0;
            hue_index=hue_index+10;
        }
        else if (brightness_index <= 0)
        {
            toggle=1;
            hue_index=hue_index+10;
        }

        if (toggle)
        {
            brightness_index++;
        }
        else
        {
        brightness_index--;
        }
        
        if (hue_index >= 255) {
            hue_index = 0;
        }
        
        delayMultiplier = 2;
        showleds();        
    }
}

    

  
void effect2 ()
{

    

    //EFFECT RIPPLE
    if (strip_effect == "ripple") {
      for (int i = 0; i < NUM_LEDS; i++) leds[i] = CHSV(bgcol++, 255, 15);  // Rotate background colour.
      switch (step) {
        case -1:                                                          // Initialize ripple variables.
          center = random(NUM_LEDS);
          colour = random8();
          step = 0;
          break;
        case 0:
          leds[center] = CHSV(colour, 255, 255);                          // Display the first pixel of the ripple.
          step ++;
          break;
        case maxsteps:                                                    // At the end of the ripples.
          step = -1;
          break;
        default:                                                             // Middle of the ripples.
          leds[(center + step + NUM_LEDS) % NUM_LEDS] += CHSV(colour, 255, myfade / step * 2);   // Simple wrap from Marc Miller
          leds[(center - step + NUM_LEDS) % NUM_LEDS] += CHSV(colour, 255, myfade / step * 2);
          step ++;                                                         // Next step.
          break;
      }
      if (transitionTime == 0 ) {
        transitionTime = 30;
      }
      delayMultiplier = 1;
      showleds();
    }

  }


 
void effect3(String strip_effect)
{
  //FLASH AND FADE SUPPORT
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
    if (startFade && strip_effect == "solid") 
    {
    // If we don't want to fade, skip it.
        if (transitionTime == 0) 
        {
            setColor(realRed, realGreen, realBlue);

            redVal = realRed;
            grnVal = realGreen;
            bluVal = realBlue;

            startFade = false;
        }
        else 
        {
            loopCount = 0;
            stepR = calculateStep(redVal, realRed);
            stepG = calculateStep(grnVal, realGreen);
            stepB = calculateStep(bluVal, realBlue);

            inFade = true;
        }
    }

    if (inFade) 
    {
        startFade = false;
        unsigned long now = millis();
        if (now - lastLoop > transitionTime) 
        {
            if (loopCount <= 1020) 
            {
                lastLoop = now;
                redVal = calculateVal(stepR, redVal, loopCount);
                grnVal = calculateVal(stepG, grnVal, loopCount);
                bluVal = calculateVal(stepB, bluVal, loopCount);

                if (strip_effect == "solid") 
                {
                    setColor(redVal, grnVal, bluVal); // Write current values to LED pins
                }
                loopCount++;
            }
            else {
                inFade = false;
            }
        }
    }
}


//ColorWavesWithPalettes by Mark Kriegsman: https://gist.github.com/kriegsman/8281905786e8b2632aeb
// This function draws color waves with an ever-changing,
// widely-varying set of parameters, using a color palette.
void colorwaves()
{
  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;

  // uint8_t sat8 = beatsin88( 87, 220, 250);
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 300, 1500);

  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5, 9);
  uint16_t brightnesstheta16 = sPseudotime;

  for ( uint16_t i = 0 ; i < NUM_LEDS; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;
    uint16_t h16_128 = hue16 >> 7;
    if ( h16_128 & 0x100) {
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

    CRGB newcolor = ColorFromPalette(gCurrentPalette, index, bri8);

    nblend(leds[i], newcolor, 128);
  }
}

//EFFECT NOISE

void add_noises() 
{
    for (int i = 0; i < NUM_LEDS; i++) 
    {                                     // Just onE loop to fill up the LED array as all of the pixels change.
    uint8_t index = inoise8(i * scale, dist + i * scale) % 255;            // Get a value from the noise function. I'm using both x and y axis.
    leds[i] = ColorFromPalette(currentPalette, index, 255, LINEARBLEND);   // With that value, look up the 8 bit colour palette value and assign it to the current LED.
    }
    dist += beatsin8(10, 1, 4);                                              // Moving along the distance (that random number we started out with). Vary it a bit with a sine wave.
    // In some sketches, I've used millis() instead of an incremented counter. Works a treat.
    if (transitionTime == 0 ) 
    {
    transitionTime = 0;
    }
    delayMultiplier = 1;
    showleds();
}
void add_glitter(int chance_of_glitter, int number_of_glitters )
{ 
    int r = random8(100);
    if( r < chance_of_glitter ) 
    {
        for( int j = 0; j < number_of_glitters; j++) 
        {
        int pos = random16( NUM_LEDS);
        leds[pos] = CRGB::White; // very bright glitter
        }
    }
}
void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    for( int i = 0; i < NUM_LEDS; i++) 
    {
        leds[i] = ColorFromPalette( gCurrentPalette, colorIndex);
        colorIndex += 3;
    }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}