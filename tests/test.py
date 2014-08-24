import json
import time

import handystats

json_config = {
    "handystats": {
        "incremental-statistics": {
            "moving-average-alpha": 0.1,
            "moving-interval": 1000},
        "timer": {
            "idle-timeout": 1000},
        "metrics-dump": {
            "interval": 200}
    }
}


class TestHandystats(object):

    def setup(self):
        handystats.init()

    def teardown(self):
        handystats.finalize()

    def test_counter(self):
        handystats.counter_init("noxiouz", 100)
        handystats.counter_increment("noxiouz", 1)

        time.sleep(0.5)
        data = json.loads(handystats.json_dump())
        assert data["noxiouz"]["value"] == 101, data["noxiouz"]["value"]

        handystats.counter_change("noxiouz", 1)
        handystats.counter_decrement("noxiouz", 1)

    def test_timer(self):
        TIMER_ID = 9999
        handystats.timer_init("noxiouz_timer", TIMER_ID)
        handystats.timer_start("noxiouz_timer", TIMER_ID)
        time.sleep(0.5)
        handystats.timer_stop("noxiouz_timer", TIMER_ID)

        # wait to flush stats
        time.sleep(0.5)
        data = json.loads(handystats.json_dump())
        value = data["noxiouz_timer"]
        assert 500000 < data["noxiouz_timer"]["value"] < 600000, value


class TestConfiguration(object):

    def test_json_configuration(self):
        handystats.configuration_json(json.dumps(json_config))

    def test_json_configuration2(self):
        handystats.configuration_json("sdsd")


class TestObjects(object):

    def test_counter(self):
        counter = handystats.Counter()
        counter.increment(100)
        counter.decrement(50)
        assert counter.value == 50, counter.value
        counter.value = 1
        assert counter.value == 1, counter.value
