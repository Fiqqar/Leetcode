class Solution:
    def convertDateToBinary(self, date: str) -> str:
        parts = date.split("-")
        binary = []
        for part in parts:
            integer_part = int(part)
            binary.append(f"{integer_part:b}")
        return "-".join(binary)
        