# Constants
number_of_doorbell_rings = 5  # Number of doorbell rings per day

battery_capacity_uAh = 1200000  # Battery capacity in µAh, converted from 1200mAh
consumption_high_uA = 24930  # High consumption in µA, converted from 32mA
consumption_low_uA = 73  # Low consumption in µA
high_consumption_duration_s = 34  # Duration of high consumption in seconds
total_day_seconds = 86400  # Total seconds in a day

high_consumption_duration_s = high_consumption_duration_s * number_of_doorbell_rings  # Multiply by the number of doorbell rings

# Calculate the total consumption in µAh for each period
high_consumption_total_uAh = consumption_high_uA * high_consumption_duration_s / 3600  # Convert seconds to hours
low_consumption_duration_s = total_day_seconds - high_consumption_duration_s
low_consumption_total_uAh = consumption_low_uA * low_consumption_duration_s / 3600  # Convert seconds to hours

# Calculate the total average daily consumption in µAh
average_daily_consumption_uAh = high_consumption_total_uAh + low_consumption_total_uAh

# Calculate the battery life in days
battery_life_days = battery_capacity_uAh / average_daily_consumption_uAh
# Calculate the battery life in years
battery_life_years = battery_life_days / 365

# Echo out the values
print(f"Estimated battery life: {battery_life_days:.2f} days or {battery_life_years:.2f} years")
