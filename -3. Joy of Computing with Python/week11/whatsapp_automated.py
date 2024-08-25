from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time



chrome_driver_path = "/Users/praveenkumar/Desktop/programs cpp/programs/-3. Joy of Computing with Python/chromedriver"

# Set up Chrome options
chrome_options = Options()
# Set other options if needed
# chrome_options.add_argument("--headless")

service = Service(chrome_driver_path)

# options = webdriver.ChromeOptions()
chrome_options.add_argument("user-data-dir=/Users/praveenkumar/Library/Application Support/Google")
chrome_options.add_experimental_option("detach", True)
driver = webdriver.Chrome(service=service, options=chrome_options)

driver.get("https://web.whatsapp.com/")
wait=WebDriverWait(driver,100)

target='"Sagar 2nd Year COE"'
message="Automated message! "
number_of_times= 30 #No. of times to send a message

contact_path='//span[contains(@title,'+ target +')]'
contact=wait.until(EC.presence_of_element_located((By.XPATH,contact_path)))
contact.click()
message_box_path='//*[@id="main"]/footer/div[1]/div/span[2]/div/div[2]/div[1]/div/div[1]/p'

for x in range(number_of_times):
    message_box=wait.until(EC.presence_of_element_located((By.XPATH,message_box_path)))
    message_box.send_keys(message + Keys.ENTER)
    # time.sleep(0.1)