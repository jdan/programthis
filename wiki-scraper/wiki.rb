#!/usr/bin/env ruby

# wiki-scraper.rb by Jordan Scales
# http://jordanscales.com
# http://programthis.net
#
# Tests the idea that the first link on each wikipedia article
#   will eventually lead to philosophy
#
# Usage:
#   ruby wiki-scraper.rb daft punk

require 'nokogiri'
require 'open-uri'
require 'cgi'

ROOT_URL = 'http://en.wikipedia.org'

def search_url(query)
  "http://en.wikipedia.org/w/index.php?search=#{CGI.escape(query)}"
end

def title_from_url(url)
  doc = Nokogiri::HTML(open(url))
  doc.css('h1#firstHeading').first.content
end

def title_from_query(query)
  title_from_url search_url(query)
end

def first_link(url)
  doc = Nokogiri::HTML(open(url))
  parenth = 0
  
  # cycle through each paragraph
  doc.css('div.mw-content-ltr > p').each do |p|
    
    # in each paragraph, go through each node
    p.children.each do |c|
      
      # if we've found two parentheses, return the next link you see
      if parenth == 0 or (parenth > 1 and (parenth % 2 == 0))
        if c.name == 'a'
          return ROOT_URL + c.attributes["href"].value
        end
      end
    
      # incremement the number of parentheses we've seen
      if /\(/ === c.to_s
        parenth += 1
      elsif /\)/ === c.to_s
        parenth += 1
      end
    end
  end
end

def first_link_from_query(query)
  first_link search_url(query)
end

start = ARGV.join(' ')
url = search_url start
title = title_from_url url
puts "1: #{title}"
count = 2

while title != 'Philosophy'
  url = first_link url
  title = title_from_url url
  puts "#{count}: #{title}: #{url}"
  count += 1
end
