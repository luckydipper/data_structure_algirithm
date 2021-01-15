#달러당 열량이 최대
#내생각앤 적으니깐 그냥 simulation 으로 해도 될 것같은데?
#아니군 combination으로 toping을 가져오려면, 100c0+100c1 +...+ 100c100

#평균도 아님 분모는 분모끼리 분자는 분짜끼리 더해야함. 하아나. 가성비 계산해놓고 더하면 안되는듯.?



#next time
#가성비가 가장 좋은 토핑을 고르고 고르기전과, 고른 후 전체 가성비 차이를 계산해야할 듯
# 그냥 자체적으로 정렬을 하고 실행하면, list의 변환 없이도 가능하겠다.


toping_num = 3
dow_toping_dolor = "12 2"

dow_dolor = 12
toping_dolor = 2
dow_cal = 50

toping_cal  = [50, 300, 100]

dow_ga_sung_bi = 50 / 12

toping_ga_sung_bi = [cal/toping_dolor for cal in toping_cal]


chose_toping_num = 2

most_good_toping = max(toping_ga_sung_bi)
toping_ga_sung_bi.remove(most_good_toping)

    
first_average_gasung = (most_good_toping + dow_ga_sung_bi) / chose_toping_num

average_gasung = first_average_gasung

while average_gasung < most_good_toping :
    if toping_ga_sung_bi == []:
        break
    most_good_toping = max(toping_ga_sung_bi)
    toping_ga_sung_bi.remove(most_good_toping)
    chose_toping_num += 1
    average_gasung = (most_good_toping + average_gasung) / chose_toping_num

print(average_gasung)

