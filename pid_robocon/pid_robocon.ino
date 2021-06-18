#define DESIRE_VALUE 100
#define kp 100
#define kd 100
#define ki 100
#define time_for_one_count 100
#define total_time_for_overflow 100;
#define SOMTHING 100

int sec           = 0;
int timee         = 0;
int elapsed_time  = 0;
int prevTime      = 0;
int overFlow      = 0;

int read_value    = 0;
int prev_error    = 0;
int error         = 0;
int pid_p         = 0;
int pid_d         = 0;
int pid_i         = 0;
int PID_value     = 0;

void PID_init(int sensor_nu_reading);
void start_counting_sec();

void setup()
{
  
}

void loop()
{
  
}

void PID_init(int sensor_nu_reading)
{
    start_counting_sec();
    timee = sec + TCNT5*time_for_one_count;
    read_value = sensor_nu_reading;

    error = DESIRE_VALUE - read_value; 

    pid_p = kp * error;
    if(-SOMTHING < error < SOMTHING)
    {
        pid_i = pid_i + ki*error;
    }

    prevTime = timee;
    timee = sec + TCNT2*time_for_one_count;
    elapsed_time = (timee - prevTime);
    pid_d = kd*( (error - prev_error) / elapsed_time );

    PID_value = pid_p + pid_i + pid_d;
    
    if(PID_value < 0) { PID_value = 0; }
    if(PID_value > 255) { PID_value = 255; } 

    prev_error = error;
}

void start_counting_sec()
{

  TCNT5 = 0;
  TCCR5B = 0;
  TCCR5A = (0 << WGM50);  // NORMAL MODE 
  TIMSK5 = (1 << TOIE5); // INTURRUPT ENABLE 

  TCCR5B = (1 << CS50); // TIMER COUNTER START

}

ISR (TIMER5_OVF_vect)
{
  overFlow++;
  sec = sec + overFlow*total_time_for_overflow;
}
