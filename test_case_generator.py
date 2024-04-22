import random


def generate_and_save_test_cases(max_buggies, max_people, filename):
    with open(filename, 'w') as file:
        N = max_buggies
        buggies = [random.randint(1, max_people) for _ in range(N)]
        actions = []
        for _ in range(1, N + 1):
            action_type = random.choice(['a', '?'])
            if action_type == 'a':
                actions.append(f'{action_type} {random.randint(1, N)}')

            else:
                actions.append(f'{action_type} {random.randint(1, N)}')
        file.write(f"{N}\n")
        file.write(' '.join(map(str, buggies)) + '\n')
        for action in actions:
            file.write(action + '\n')
        file.write('\n')


def main():
    max_buggies = int(1e5)
    max_people = int(1e5)
    generate_and_save_test_cases(max_buggies, max_people, "test_cases_large.txt")
    print("Test cases saved to 'test_cases_large.txt'.")


if _name_ == "_main_":
    main()
