from typing import List

class WordFilter:

    def __init__(self, words: List[str]):
        self.prefix_suffix_map = {}
        for index, word in enumerate(words):
            length = len(word)
            for i in range(length + 1):
                prefix = word[:i]  # 가능한 모든 접두사
                for j in range(length + 1):
                    suffix = word[j:]  # 가능한 모든 접미사
                    self.prefix_suffix_map[(prefix, suffix)] = index

    def f(self, pref: str, suff: str) -> int:
        # 미리 계산된 맵에서 결과를 직접 반환
        return self.prefix_suffix_map.get((pref, suff), -1)

# 사용 예시:
# obj = WordFilter(["apple", "banana", "orange"])
# param_1 = obj.f("a", "e")  # 가장 마지막에 나타나는 "apple"의 인덱스를 반환
