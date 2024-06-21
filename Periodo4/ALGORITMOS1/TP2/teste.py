import random


def generate_input(n, m):
  """Gera uma entrada para o problema da construção de estradas com N vilas e M conexões.

  Args:
    n: O número de vilas.
    m: O número de conexões.

  Returns:
    Uma string com a entrada gerada.
  """

  # Gera as vilas.
  villages = list(range(1, n + 1))

  # Gera as conexões.
  connections = []
  for _ in range(m):
    u = random.choice(villages)
    v = random.choice(villages)
    a = random.randint(1, 108)
    l = random.randint(1, 105)
    c = random.randint(1, 105)
    connections.append((u, v, a, l, c))

  # Gera a entrada.
  input_string = f"{n} {m}\n"
  for u, v, a, l, c in connections:
    input_string += f"{u} {v} {a} {l} {c}\n"

  return input_string


def main():
  # Gera uma entrada com N = 10^6 vilas e M = 10^6 conexões.
  input_string = generate_input(1000000, 1000000)

  # Imprime a entrada.
  print(input_string)


if __name__ == "__main__":
  main()