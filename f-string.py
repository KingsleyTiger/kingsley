import requests
from bs4 import BeautifulSoup
LIMIT=50
url = f"https://www.indeed.com/jobs?q=python&limit={LIMIT}"

#return page`s number
def get_last_pages():

    #bring url
    result = requests.get(url)

    #bring html
    #print(indeed_result.text)

    #bring page numbers
    soup = BeautifulSoup(result.text,"html.parser")
    pagination = soup.find("div",{"class":"pagination"})  #bring class=pagination in <div> tag

    links = pagination.find_all('a') #bring all <a>
    pages=[]
    for link in links[:-1]:  #except last one
        pages.append(int(link.find("span").string))  #change int type that <span> find in links. then append to pages[]

    #last page
    max_page = pages[-1]

    return max_page

def extract_job(html):
    title = html.find("h2",{"class":"title"}).find("a")["title"]  #find title in a in class:title in <h2>
    company = html.find("span",{"class":"company"})
    company_anchor = company.find("a")
    if company_anchor is not None:
        company = (str(company.find("a").string))
    else:
        company = str(company.string)
    company = company.strip()   #delete whitespace
    location = html.find("div",{"class":"recJobLoc"})["data-rc-loc"]
    job_id = html["data-jk"]

    return {'title':title,
            'company':company,
            'location':location,
            "link":f"https://www.indeed.com/viewjob?jk={job_id}"}


#connect to pages and get title
def output_jobs(last_page):
    jobs=[]
    for page in range(last_page):  #last_page is extract_indeed_pages()=page`s number
        result = requests.get(f"{url}&start={page*LIMIT}") #get url
        soup = BeautifulSoup(result.text,"html.parser") #get html
        results = soup.find_all("div",{"class":"jobsearch-SerpJobCard"})    #find class:~ in div

    #in all results
    for result in results:
        job = extract_job(result)
        jobs.append(job)
    return jobs


def get_jobs():
    last_pages = get_last_pages()

    jobs = output_jobs(last_pages)
    return jobs
