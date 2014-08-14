import json
import time

import handystats as handy


json_config = {
    "handystats": {
        "incremental-statistics": {
                      "moving-average-alpha": 0.1,
                      "moving-interval": 1000},
    "timer": {"idle-timeout": 1000},
    "metrics-dump": {"interval": 200}
    }
}


class TestHandystats(object):

    def setup(self):
        handy.init()

    def teardown(self):
        handy.finalize()

    def test_counter(self):
        handy.counter_init("noxiouz", 100)
        handy.counter_increment("noxiouz", 1)

        time.sleep(0.5)
        data = json.loads(handy.json_dump())
        assert data["noxiouz"]["value"] == 101, data["noxiouz"]["value"]

        handy.counter_change("noxiouz", 1)
        handy.counter_decrement("noxiouz", 1)

    def test_timer(self):
        TIMER_ID = 9999
        handy.timer_init("noxiouz_timer", TIMER_ID)
        handy.timer_start("noxiouz_timer", TIMER_ID)
        time.sleep(0.5)
        handy.timer_stop("noxiouz_timer", TIMER_ID)

        # wait to flush stats
        time.sleep(0.5)
        data = json.loads(handy.json_dump())
        value = data["noxiouz_timer"]
        assert 500000 < data["noxiouz_timer"]["value"] < 600000, value


class TestConfiguration(object):

    def test_json_configuration(self):
        handy.configuration_json(json.dumps(json_config))

    def test_json_configuration2(self):
        handy.configuration_json("sdsd")
