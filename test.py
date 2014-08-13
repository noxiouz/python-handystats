import _handystats as handy
import time

print dir(handy)

handy.handy_init()

handy.handy_counter_init("noxiouz", 100)
handy.handy_counter_increment("noxiouz", 1)

TIMER_ID = 9999
handy.handy_timer_init("noxiouz_timer", TIMER_ID)
handy.handy_timer_start("noxiouz_timer", TIMER_ID)
time.sleep(5)
handy.handy_timer_stop("noxiouz_timer", TIMER_ID)
time.sleep(2)
print handy.handy_json_dump()

handy.handy_counter_change("noxiouz", 1)
handy.handy_counter_decrement("noxiouz", 1)
