class Calculator:
    name = 'good calcolator'
    price = 18

    def add(self, x, y):
        print(self.name)
        result = x + y
        print(result)

    def minus(self, x, y):
        result = x - y
        return result

    def times(self, x, y):
        return x * y

    def divide(self, x, y):
        return x / y


a = Calculator()
a.add(2, 3)
