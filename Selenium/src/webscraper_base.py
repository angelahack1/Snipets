from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Create a new instance of the Firefox driver
driver = webdriver.Firefox()

try:
    # Go to the Google home page
    driver.get("http://www.google.com")

    # Find the search box element
    search_box = driver.find_element_by_name("q")

    # Type "Python" into the search box
    search_box.send_keys("Python")

    # Submit the search
    search_box.submit()

    # Wait for the search results page to load
    WebDriverWait(driver, 10).until(EC.title_contains("Python"))

    # Print the page title
    print(driver.title)

finally:
    # Close the browser
    driver.quit()