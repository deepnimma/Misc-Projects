from PyPDF2 import PdfFileMerger

volumes = 0
starting_volume = 0

volumes = int(input('Enter Number of Volumes: '))
start_pages = []
end_pages = []

starting_volume = int(input('Enter Starting Volume Number: '))

for current_volume in range(0, volumes):
    start_page = 0
    end_page = 0

    start_page = int(input('Enter Start Page of Volume %s: ' % (current_volume + 1)))
    end_page = int(input('Enter End Page of Volume %s: ' % (current_volume + 1)))
    print('\n')

    start_pages.append(start_page)
    end_pages.append(end_page)    

    # start_pages += str(start_page)
    # end_pages += str(end_page)

for current_volume in range(0, volumes):
    chapters = []
    chapter_file_name = []

    beginning_chapter = start_pages[current_volume]
    ending_chapter = end_pages[current_volume]

    for i in range(beginning_chapter, ending_chapter + 1):
        chapters.append(i)
        chapter_file_name.append(str(i) + '.pdf')
        print('Chapter %d Added to List...' % (i))

    merger = PdfFileMerger()

    print('Merger Created')

    for pdf in chapter_file_name:
        merger.append(pdf)
        print('%s added...' % (pdf))

    final_file_name = 'Volume ' + str(starting_volume) + '.pdf'
    starting_volume += 1

    merger.write(final_file_name)
    merger.close()

    print(final_file_name + " Completed! \n")

    # print(final_file_name)

    # print(chapters, chapter_file_name)


# pdfs = ['1.pdf', '2.pdf', '3.pdf', '4.pdf', '5.pdf', '6.pdf', '7.pdf']

# merger = PdfFileMerger()

# for pdf in pdfs:
#     merger.append(pdf)

# merger.write('Volume 1.pdf')
# merger.close()