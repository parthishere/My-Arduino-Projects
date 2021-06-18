void setup()
{
 uint8_t sreg = SREG;
    cli();

    // Stop timer before configuring
    TCCR1B = 0;

    // 16.11.1 TCCR1A – Timer/Counter1 Control Register A
    TCCR1A =
        0
        | (1 << COM1A1) | (0 << COM1A0)  // Clear OC1A on Compare Match, set OC1A at BOTTOM (non-inverting mode)
        | (1 << COM1B1) | (0 << COM1B0)  // Clear OC1B on Compare Match, set OC1B at BOTTOM (non-inverting mode)
        | (1 << WGM11) | (0 << WGM10)    // Fast PWM mode 14 (TOP = ICR1), part 1/2
        ;

    // 16.11.2 TCCR1B – Timer/Counter1 Control Register B
    TCCR1B =
        0
        | (1 << WGM13) | (1 << WGM12)    // Fast PWM mode 14 (TOP = ICR1), part 2/2
        ;

    // IMPORTANT NOTE ABOUT ORDER OF INITIALIZATION:
    //   "The ICR1 Register can only be written when using a Waveform
    //   Generation mode that utilizes the ICR1 Register for defining
    //   the counter’s TOP value. In these cases the Waveform
    //   Generation mode (WGM13:0) bits must be set before the TOP
    //   value can be written to the ICR1 Register."
    // Thus initializing OCR1 before TCCR1A and TCCR1B has been
    // configured with Fast PWM mode 14 is wrong.

    // Set TOP value
    ICR1 = 0xFFFF;

    // IMPORTANT NOTE ABOUT ORDER OF INITIALIZATION:
    //   "The OCR1x Register is double buffered when using any of the
    //   twelve Pulse Width Modulation (PWM) modes. For the Normal
    //   and Clear Timer on Compare (CTC) modes of operation, the
    //   double buffering is disabled."
    // If initializing OCR1A before configuring TCCR1A and TCCR1B to
    // a PWM mode the value is written to the non-buffered OCR1A
    // register and the buffered OCR1A register contains some "random",
    // unused garbage value. When later changing to PWM the buffered
    // register will be enabled, and its existing garbage value will
    // be used.
    // Thus initializing OCR1A/OCR1B before TCCR1A and TCCR1B has
    // been configured with Fast PWM is wrong.

    // 25% duty cycle - yellow scope signal
    OCR1A = 0x3FFF;

    // 75% duty cycle - blue scope signal
    OCR1B = 0xBFFF;

    // 14.4.3 DDRB – The Port B Data Direction Register
    DDRB =
        0
        | (1 << DDB1) // PB1 (aka OC1A) as output - pin 9 on Arduino Uno
        | (1 << DDB2) // PB2 (aka OC1B) as output - pin 10 on Arduino Uno
        ;

    // Start the timer with no prescaler
    TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10);

    SREG = sreg;
}


void loop() {
  // put your main code here, to run repeatedly:

}
