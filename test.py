import _handystats as handy
import time

print dir(handy)

handy.handy_init()
handy.handy_json_dump()

handy.handy_counter_init("noxiouz", 100)
handy.handy_counter_increment("noxiouz", 1)

time.sleep(2)
print handy.handy_json_dump()

handy.handy_counter_change("noxiouz", 1)
handy.handy_counter_decrement("noxiouz", 1)
