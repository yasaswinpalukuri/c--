'''
Monte Carlo Simulation
    -> is a computerized mathematical technique that allows people to account for risk in quantitative analysis and decision making.
    -> It is used to understand the impact of risk and uncertainty in prediction and forecasting models.
    -> It is a statistical method used to understand the impact of risk and uncertainty in financial, project management, cost, and other forecasting models.
    -> Time Complexity: O(n), where n is the number of iterations.
    -> Space Complexity: O(1).

'''

import random 

def monte_carlo_simulation(iterations):
    inside_circle = 0
    total_points = 0

    for _ in range(iterations):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)

        distance = x**2 + y**2

        if distance <= 1:
            inside_circle += 1

        total_points += 1

    pi_estimate = 4 * (inside_circle / total_points)
    return pi_estimate

# Example usage
num_iterations = 1000000
estimated_pi = monte_carlo_simulation(num_iterations)
print(f"Estimated value of pi: {estimated_pi}")