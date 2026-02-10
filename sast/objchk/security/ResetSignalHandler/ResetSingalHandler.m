void handler2(int signum)
{
  if (signal(signum, handler2) == SIG_ERR) // @violation
  {
 /* Handle error */
 abort();
  }
  e_flag = 1;
}


void handle()
{
    struct sigaction act;
    act.sa_handler = handler;
    act.sa_flags = 0;
    if (sigemptyset(&act.sa_mask) != 0) {
      /* Handle error */
    }
    if (sigaction(SIGUSR1, &act, NULL) != 0) {
      /* Handle error */
    }
}