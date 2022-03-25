from lazyEdge import lazyEdge
from mybdfy import translate
from tqdm import tqdm
import json
edge=lazyEdge()
def getzhabst(title:str):
    edge.get("https://dblp.org/search?q="+"+".join(title.split()))
    ee=edge.find_element_by_class_name("ee")
    a=ee.find_element_by_tag_name("a")
    edge.get(a.get_attribute("href"))
    if "epubs.siam.org/doi/" in edge.current_url:
        abst=edge.find_element_by_id("bookExcerpt").get_attribute("innerText")
    elif "dl.acm.org/doi/" in edge.current_url:
        abst=edge.find_element_by_css_selector(".abstractSection.abstractInFull").get_attribute("innerText")
    elif "ieeexplore.ieee.org/document" in edge.current_url:
        abst=edge.find_element_by_class_name("abstract-desktop-div").find_element_by_css_selector("div.u-mb-1").get_attribute("innerText")
    elif "ojs.aaai.org/index.php/AAAI/article/view/" in edge.current_url:
        abst=edge.find_element_by_css_selector("section.item.abstract").get_attribute("innerText")
    elif "link.springer.com/article/" in edge.current_url:
        abst=edge.find_element_by_css_selector("#Abs1-content").get_attribute("innerText")
    elif "www.combinatorics.org/ojs/index.php" in edge.current_url:
        abst=edge.find_element_by_css_selector("div.item.abstract").get_attribute("innerText")
    elif "pubsonline.informs.org/doi" in edge.current_url:
        abst=edge.find_element_by_css_selector("div.abstractSection.abstractInFull").get_attribute("innerText")
    else:
        return (edge.current_url)
    return translate(abst)
