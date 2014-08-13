import json
import time

import handystats as handy


class TestHandystats(object):

    def setup(self):
        handy.handy_init()

    def teardown(self):
        handy.handy_finalize()

    def test_counter(self):
        handy.handy_counter_init("noxiouz", 100)
        handy.handy_counter_increment("noxiouz", 1)

        time.sleep(0.5)
        data = json.loads(handy.handy_json_dump())
        assert(data["noxiouz"]["value"] == 101)

        handy.handy_counter_change("noxiouz", 1)
        handy.handy_counter_decrement("noxiouz", 1)

    def test_timer(self):
        TIMER_ID = 9999
        handy.handy_timer_init("noxiouz_timer", TIMER_ID)
        handy.handy_timer_start("noxiouz_timer", TIMER_ID)
        time.sleep(0.5)
        handy.handy_timer_stop("noxiouz_timer", TIMER_ID)

        # wait to flush stats
        time.sleep(0.5)
        data = json.loads(handy.handy_json_dump())
        value = data["noxiouz_timer"]
        assert 500000 < data["noxiouz_timer"]["value"] < 600000, value
