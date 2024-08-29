import time

counts = {}


def counter(counter_name):
    def decorator(func):
        def wrapper(*args, **kwargs):
            result = func(*args, **kwargs)
            if counter_name not in counts:
                counts[counter_name] = 0
            counts[counter_name] += 1
            return result

        return wrapper

    return decorator
