import time
import random
import os
import subprocess
import clipboard
from selenium.webdriver import Chrome
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options

baekjoon_id = "jkh0515"
now_mode = 1

command = [
    "C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe",
    "--remote-debugging-port=9222",
    "--user-data-dir=c:\\ChromeTEMP"
]

language_list = {"C99" : ["/C", ".c", "//"], "C++17" : ["/C++", ".cpp", "//"], "Python 3" : ["/Python", ".py", "#"], "PyPy3" : ["/Python", ".py", "#"]}

tier_kind = ["Unranked", "Bronze", "Silver", "Gold", "Platinum"]

tier_index = {"/1" : "Bronze 5", "/2" : "Bronze 4", "/3" : "Bronze 3", "/4" : "Bronze 2", "/5" : "Bronze 1", 
              "/6" : "Silver 5", "/7" : "Silver 4", "/8" : "Silver 3", "/9" : "Silver 2", "10" : "Silver 1", 
              "11" : "Gold 5", "12" : "Gold 4", "13" : "Gold 3", "14" : "Gold 2", "15" : "Gold 1", 
              "16" : "Platinum 5", "17" : "Platinum 4", "18" : "Platinum 3", "19" : "Platinum 2", "20" : "Platinum 1",
                "-1" : "Unranked"}

tier_detail = {"Bronze 5" : [], "Bronze 4" : [], "Bronze 3" : [], "Bronze 2" : [], "Bronze 1" : [], 
            "Silver 5" : [], "Silver 4" : [], "Silver 3" : [], "Silver 2" : [], "Silver 1" : [], 
            "Gold 5" : [], "Gold 4" : [], "Gold 3" : [], "Gold 2" : [], "Gold 1" : [], 
            "Platinum 5" : [], "Platinum 4" : [], "Platinum 3" : [], "Platinum 2" : [], "Platinum 1" : [], 
            "Unranked" : []}

subprocess.Popen(command)

time.sleep(0.5)

chrome_options = Options()
chrome_options.add_experimental_option("debuggerAddress", "127.0.0.1:9222")

driver = Chrome(options=chrome_options)

try :
  now_mode = 1
  old_list = open("solved_problem_list.txt", "r", encoding="utf-8")
  strlist = old_list.read()
  old_list.close()
  tier_detail = eval(strlist)
  solved_num = input("추가할 문제번호를 입력해주세요 : ")
  driver.get(f"https://www.acmicpc.net/status?problem_id={solved_num}&user_id={baekjoon_id}&language_id=-1&result_id=4&from_mine=1")
  print(f"plus[{solved_num}]")
except :
  now_mode = 0
  driver.get(f"https://www.acmicpc.net/status?problem_id=&user_id={baekjoon_id}&language_id=-1&result_id=4")

info_list = list(list())

end_num, base_delay = 0, 1

now_dir = os.path.dirname(os.path.realpath(__file__))
try : 
  os.makedirs(now_dir + "/code")
  code_dir = now_dir + "/code"
except :
  code_dir = now_dir + "/code"

while(1) :
  page_list = list()
  tr_list = driver.find_elements(By.TAG_NAME, "tr")
  for tr in tr_list:
      td_list = tr.find_elements(By.TAG_NAME, "td")
      a_list = tr.find_elements(By.TAG_NAME, "a")
      if len(td_list) == 0 : continue

      tier_img = tr.find_element(By.TAG_NAME, "img").get_attribute("src")
      tier = tier_index[tier_img[-6:-4]]
      if tier == "Unranked" :
          try : 
              tr_info = [td_list[0].text, td_list[2].text[1:], str(a_list[1].get_attribute("data-original-title")), td_list[4].text, 
                  td_list[5].text, a_list[3].text, str(a_list[5].get_attribute("data-original-title")), tier]
          except IndexError :
              tr_info = [td_list[0].text, td_list[2].text[1:], str(a_list[1].get_attribute("data-original-title")), td_list[4].text, 
                  td_list[5].text, a_list[3].text, str(a_list[4].get_attribute("data-original-title")), tier]
          if(tr_info[5] == "수정") : tr_info[5] = a_list[2].text
      else :
          tr_info = [td_list[0].text, td_list[2].text[1:], str(a_list[1].get_attribute("data-original-title")), td_list[4].text, 
                  td_list[5].text, a_list[2].text, str(a_list[4].get_attribute("data-original-title")), tier]
          if(tr_info[5][-1:] == "점") : 
              tr_info[5] = a_list[3].text
              tr_info[6] = str(a_list[5].get_attribute("data-original-title"))
      page_list.append(tr_info)
      info_list.append(tr_info)
      if now_mode == 1 : break
      # print(tr_info)

  delay = base_delay + random.random()
  time.sleep(delay)

  for i in page_list :
      driver.get("https://www.acmicpc.net/source/" + i[0])
      code = str(driver.find_element(By.TAG_NAME, "textarea").get_attribute("value"))
      dir = code_dir + language_list[i[5]][0]
      name = "bj" + i[1] + language_list[i[5]][1]
      try : 
          delay = random.random()
          time.sleep(delay)
          if name in os.listdir(dir) : continue
      except :
          delay = random.random()
          time.sleep(delay)
          os.makedirs(dir)
          if name in os.listdir(dir) : continue
      tier_detail[i[7]].append(i)
      f = open(dir + "/" + name, "w", encoding = 'utf-8')
      f.write(f"{language_list[i[5]][2]}{i[1]} {i[2]} - {i[5]}\n")
      f.write(f"{language_list[i[5]][2]}메모리 : {i[3]}KB / 시간 : {i[4]}ms\n")
      f.write(f"{language_list[i[5]][2]}{i[6]}\n\n")
      f.write(code)
      f.close()
      delay = random.random() * 2
      time.sleep(delay)
  #     break
  # break
  if end_num == info_list[len(info_list)-1][0] : break
  end_num = info_list[len(info_list)-1][0]
  driver.get(f"https://www.acmicpc.net/status?user_id=jkh0515&language_id=-1&result_id=4&top={end_num}")

new_list = open("solved_problem_list.txt", "w", encoding = 'utf-8')
new_list.write(str(tier_detail))
new_list.close()

solved_total = list([0] for _ in range(5))

solved_total[0] = len(tier_detail["Unranked"])
solved_total[1] = len(tier_detail["Bronze 5"]) + len(tier_detail["Bronze 4"]) + len(tier_detail["Bronze 3"]) + len(tier_detail["Bronze 2"]) + len(tier_detail["Bronze 1"])
solved_total[2] = len(tier_detail["Silver 5"]) + len(tier_detail["Silver 4"]) + len(tier_detail["Silver 3"]) + len(tier_detail["Silver 2"]) + len(tier_detail["Silver 1"])
solved_total[3] = len(tier_detail["Gold 5"]) + len(tier_detail["Gold 4"]) + len(tier_detail["Gold 3"]) + len(tier_detail["Gold 2"]) + len(tier_detail["Gold 1"])
solved_total[4] = len(tier_detail["Platinum 5"]) + len(tier_detail["Platinum 4"]) + len(tier_detail["Platinum 3"])

readMe = f"## 📚 푼 문제 목록 - {sum(solved_total)}문제\n"

for i in range(5) :
    if(solved_total[i] == 0) : continue
    readMe += f"\n___\n <details - open> \n <summary><b>{tier_kind[i]} - {solved_total[i]} 문제 </b></summary>\n"
    if(tier_kind[i] == "Unranked") : 
        tier_img = "https://static.solved.ac/tier_small/nr"
        detail_list = tier_detail[tier_index["-1"]]
        if(len(detail_list) == 0) : 
            readMe += "</details>\n"
            continue
        readMe += (f"<details>\n<summary><b><img src=\"{tier_img}.svg\" width=\"12px\"/> {len(detail_list)} 문제</b></summary>\n\n"
                    "|  번호  | 문제 번호 | 문제 제목 |  난이도 | 풀이 링크 |\n"
                    "| :---: | ------- | ------- | :----: | :------------: |\n")
        idx = 1
        for k in detail_list :
            readMe += (f"| {idx} | {k[1]} | [{k[2]}](https://www.acmicpc.net/problem/{k[1]}) | <img src=\"{tier_img}.svg\" width=\"12px\"/> |"
                       f"[{k[5]}](https://github.com/jkh0515/Baekjoon/blob/main/code/{language_list[k[5]][0]}/bj{k[1]}{language_list[k[5]][1]})\n")
            idx += 1
        readMe += "</details>\n"
    else :
        for j in range(5) :
            tier_img = f"https://static.solved.ac/tier_small/{(i - 1) * 5 + (j + 1)}"
            detail_list = tier_detail[tier_index[tier_img[-2:]]]
            if(len(detail_list) == 0) : 
                continue
            readMe += (f"<details>\n<summary><b><img src=\"{tier_img}.svg\" width=\"12px\"/> {len(detail_list)} 문제</b></summary>\n\n"
                        "|  번호  | 문제 번호 | 문제 제목 |  난이도 | 풀이 링크 |\n"
                        "| :---: | ------- | ------- | :----: | :------------: |\n")
            idx = 1
            for k in detail_list :
                readMe += (f"| {idx} | {k[1]} | [{k[2]}](https://www.acmicpc.net/problem/{k[1]}) | <img src=\"{tier_img}.svg\" width=\"12px\"/> |"
                           f"[{k[5]}](https://github.com/jkh0515/Baekjoon/blob/main/code{language_list[k[5]][0]}/bj{k[1]}{language_list[k[5]][1]})\n")
                idx += 1
            readMe += "</details>\n"
    readMe += "</details>\n"

# print(readMe)
readMeText = open("README.md", "w", encoding = 'utf-8')
readMeText.write(readMe)
readMeText.close()

clipboard.copy(readMe)

driver.close()